/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "ns3/core-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/network-module.h"
#include "ns3/applications-module.h"
#include "ns3/mobility-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-module.h"
#include "ns3/yans-wifi-helper.h"
#include "ns3/ssid.h"


using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("NSLab");

int main(int argc, char *argv[]){

    LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
    LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);

    Time::SetResolution (Time::NS);

    //Creating nodes
    NodeContainer lan_nodes;
    lan_nodes.Create(5);
    NodeContainer wifi_AP;
    wifi_AP.Create(1);
    NodeContainer wifi_nodes;
    wifi_nodes.Create(3);
    NodeContainer p2p1, p2p2, p2p3, p2p4, p2p5;
    p2p1.Create(2);
    p2p2.Create(1);
    p2p2.Add(p2p1.Get(1));
    p2p3.Add(p2p1.Get(1));
    p2p3.Create(1);
    p2p4.Add(p2p3.Get(1));
    p2p4.Add(lan_nodes.Get(0));
    p2p5.Add(p2p3.Get(1));
    p2p5.Add(wifi_AP);

    //Creating channels sepeartely
    PointToPointHelper point_to_point5, point_to_point2;
    point_to_point5.SetDeviceAttribute("DataRate", StringValue("5Mbps"));
    point_to_point2.SetDeviceAttribute("DataRate", StringValue("2Mbps"));
    point_to_point2.SetChannelAttribute ("Delay", StringValue("20ms"));
    CsmaHelper lan;
    lan.SetChannelAttribute ("DataRate", StringValue ("5Mbps"));
    YansWifiChannelHelper wifi_channel = YansWifiChannelHelper::Default ();
    YansWifiPhyHelper wifi_phy;
    wifi_phy.SetChannel(wifi_channel.Create());
    WifiHelper wifi;
    wifi.SetRemoteStationManager("ns3::AarfWifiManager");
    WifiMacHelper wifi_mac;
    Ssid ssid = Ssid("ns-3-ssid");

    //Initializing Net Devices(connecting nodes and channels)
    NetDeviceContainer p2p1_net, p2p2_net, p2p3_net, p2p4_net, p2p5_net, lan_net, wifi_stat_net, wifi_AP_net;
    p2p1_net = point_to_point5.Install(p2p1);
    p2p2_net = point_to_point5.Install(p2p2);
    p2p3_net = point_to_point2.Install(p2p3);
    p2p4_net = point_to_point5.Install(p2p4);
    p2p5_net = point_to_point5.Install(p2p5);
    lan_net = lan.Install(lan_nodes);
    wifi_mac.SetType ("ns3::StaWifiMac", "Ssid", SsidValue(ssid), "ActiveProbing", BooleanValue(false));
    wifi_stat_net = wifi.Install(wifi_phy, wifi_mac, wifi_nodes);
    wifi_mac.SetType ("ns3::ApWifiMac", "Ssid", SsidValue (ssid));
    wifi_AP_net = wifi.Install(wifi_phy, wifi_mac, wifi_AP);
    MobilityHelper mobility;
    mobility.SetPositionAllocator ("ns3::GridPositionAllocator",
    "MinX", DoubleValue (0.0),
    "MinY", DoubleValue (0.0),
    "DeltaX", DoubleValue (5.0),
    "DeltaY", DoubleValue (10.0),
    "GridWidth", UintegerValue (3),
    "LayoutType", StringValue ("RowFirst"));
    mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
    mobility.Install(wifi_nodes);
    mobility.Install (wifi_AP);

    //Implement internet stack,assign tcp/ip model to all nodes each
    InternetStackHelper stack;//might get confuse here,here we should install to every node exactly once.
    stack.Install(p2p1);
    stack.Install(p2p2.Get(0));
    stack.Install(p2p3.Get(1));
    stack.Install(lan_nodes);
    stack.Install(wifi_AP);
    stack.Install(wifi_nodes);

    //Assigning IPV4 addresses,only subnet id,private addresses
    Ipv4AddressHelper address, address_lan, address_wifi;
    Ipv4InterfaceContainer p2p1_interface, p2p2_interface, lan_interface, wifi_interface;
    address.SetBase("10.1.1.0", "255.255.255.0");
    address_lan.SetBase("10.1.2.0", "255.255.255.0");
    address_wifi.SetBase("10.1.3.0", "255.255.255.0");
    p2p1_interface = address.Assign(p2p1_net);
    p2p2_interface = address.Assign(p2p2_net);
    address.Assign(p2p3_net);
    address.Assign(p2p4_net);
    address.Assign(p2p5_net);
    lan_interface =  address_lan.Assign(lan_net);
    wifi_interface = address_wifi.Assign(wifi_stat_net);
    address_wifi.Assign(wifi_AP_net);

    Ipv4GlobalRoutingHelper::PopulateRoutingTables (); //adds routing table to all nodes(router or nodes everything)


    UdpEchoServerHelper echoServer1 (9);
    ApplicationContainer server1 = echoServer1.Install (lan_nodes.Get (1));
    server1.Start (Seconds (0.0));
    server1.Stop (Seconds (101.0));

    UdpEchoServerHelper echoServer2 (9);
    ApplicationContainer server2 = echoServer2.Install (wifi_nodes.Get (1));
    server1.Start (Seconds (0.0));
    server1.Stop (Seconds (100.0));

    UdpEchoClientHelper echoClient1 (lan_interface.GetAddress (1), 9);
    echoClient1.SetAttribute ("MaxPackets", UintegerValue (100));
    echoClient1.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
    echoClient1.SetAttribute ("PacketSize", UintegerValue (1024));
    ApplicationContainer client1 = echoClient1.Install (p2p1.Get (0));
    client1.Start (Seconds (1.0));
    client1.Stop (Seconds (100.0));

    UdpEchoClientHelper echoClient2 (wifi_interface.GetAddress (1), 9);
    echoClient2.SetAttribute ("MaxPackets", UintegerValue (100));
    echoClient2.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
    echoClient2.SetAttribute ("PacketSize", UintegerValue (1024));
    ApplicationContainer client2 = echoClient2.Install (p2p1.Get (0));
    client2.Start (Seconds (1.0));
    client2.Stop (Seconds (100.0));

    AsciiTraceHelper ascii;
    point_to_point5.EnableAsciiAll (ascii.CreateFileStream ("trace.tr"));

    Simulator::Stop (Seconds (100));
    Simulator::Run ();
    Simulator::Destroy ();

    return 0;

}


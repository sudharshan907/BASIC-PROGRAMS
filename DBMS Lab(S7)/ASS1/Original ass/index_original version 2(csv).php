

<title>Student Form</title>
<h2>&emsp;Enter Student Details </h2>
<form method="post" action="">
First Name:&emsp;<input type="text" name="firstname" ><br><br>
Last Name:&emsp;<input type="text" name="lastname" ><br><br>
Roll Number:<input type="text" name="rollno" ><br><br>
Email:&emsp;&emsp;&emsp;<input type="text" name="email" ><br><br>
<input type="submit" name="btn_submit" value="Insert" />
<input type="submit" name="btn_submit" value="Delete" />
<input type="submit" name="btn_submit" value="Search" />
<input type="submit" name="btn_submit" value="Update" />
<input type="submit" name="btn_submit" value="Display" />
</form>


<?php

if(!file_exists("student.csv")){
$myfile=fopen("student.csv","w");
fclose(myfile);
}


if( !empty($_POST['btn_submit']) ){


$rollno = $_POST['rollno'];
$firstname = $_POST['firstname'];
$lastname = $_POST['lastname'];
$email = $_POST['email'];


if($_POST['btn_submit']=="Insert")
{

if(  (empty($rollno))  ||  (empty($firstname))  ||  (empty($lastname))  || (empty($email))        ){
echo "Please fill all fields in the form";
}
else{
echo "You pressed INSERT<br>";

$handle = fopen("student.csv", "r");

$found = 0;
    while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
            if($data[2]==$rollno){
       $found++;
                       }
    }
    

    fclose($handle);

   if($found=='0'){
$handle = fopen("student.csv", "a");

fputcsv($handle, [$firstname,$lastname,$rollno,$email]);

fclose($handle);
 echo "Record inserted into database successfully";
}

else{
echo "Duplicate Entry entered,Insertion Unsuccessful";
}

}
}

else if($_POST['btn_submit']=="Delete")
{
if(  (empty($rollno))   ){
echo "Roll no cant be empty";
}
else{

echo "You pressed DELETE<br>";


$handle = fopen("student.csv", "r");

$found = 0;
    while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
            if($data[2]==$rollno){
       $found++;
                       }
    }
 fclose($handle);
    if($found=='0'){
      echo "No student present in file";
}
else{
   


$h1=fopen("student1.csv","w");
fclose($h1);
$h2=fopen("student1.csv","a");

$h = fopen("student.csv", "r");


    while (($data = fgetcsv($h, 1000, ",")) !== FALSE) {
            if(  $data[2]==$rollno ){
          //dont add this to new file
                       }
else {

fputcsv($h2, [$data[0],$data[1],$data[2],$data[3]]);


}
    }

    fclose($h);
     fclose($h2);
$st="student.csv";
unlink($st);
rename("student1.csv","student.csv");
echo "successful";
}

}
}


else if($_POST['btn_submit']=="Search")
{
if(  (empty($rollno)) ){
echo "Roll Number field cant be empty<br>";
}
else{
echo "You pressed SEARCH<br>";

$handle = fopen("student.csv", "r");

$found = 0;
    while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
            if($data[2]==$rollno){
       $found++;
        for ($c=0; $c < count($data); $c++) {
            echo $data[$c] ."&emsp;";
        }
        echo "<p>";
                       }
    }
    if($found=='0'){
      echo "No student records found!";
}

    fclose($handle);
     
}
}


else if($_POST['btn_submit']=="Update")
{
if(  (empty($rollno))  ||  (empty($firstname))  ||  (empty($lastname))  || (empty($email))        ){
echo "Please fill all fields in the form";
}
else{
echo "You pressed UPDATE<br>";


$handle = fopen("student.csv", "r");

$found = 0;
    while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
            if($data[2]==$rollno){
       $found++;
                       }
    }
 fclose($handle);
    if($found=='0'){
      echo "No student record found!";
}
else{
//delete now
$handle = fopen("student.csv", "r");

$found = 0;
    while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
            if($data[2]==$rollno){
       $found++;
                       }
    }
 fclose($handle);
    if($found=='0'){
      echo "No student present in file";
}
else{
   //delete and insert a new record


$h1=fopen("student1.csv","w");
fclose($h1);
$h2=fopen("student1.csv","a");

$h = fopen("student.csv", "r");


    while (($data = fgetcsv($h, 1000, ",")) !== FALSE) {
            if(  $data[2]==$rollno ){
          //dont add this to new file
                       }
else {

fputcsv($h2, [$data[0],$data[1],$data[2],$data[3]]);


}
    }

    fclose($h);
     fclose($h2);
$st="student.csv";
unlink($st);
rename("student1.csv","student.csv");


//insert now


$handle = fopen("student.csv", "a");

fputcsv($handle, [$firstname,$lastname,$rollno,$email]);

fclose($handle);
 echo "Record updated into database successfully";


}
}
}
}
else if($_POST['btn_submit']=="Display")
{

echo "You pressed DISPLAY<br>";

$handle = fopen("student.csv", "r");

$row = 0;
    while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
        $num = count($data);
        $row++;
        for ($c=0; $c < $num; $c++) {
            echo $data[$c] ."&emsp;";
        }
        echo "<p>";
    }
    if($row=='1'){
      echo "No student records found!";
}
    fclose($handle);
}

}
?>
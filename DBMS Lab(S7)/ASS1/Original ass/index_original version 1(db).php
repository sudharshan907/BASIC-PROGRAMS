

<title>Student Form</title>
<h2>&emsp;Enter Student Details </h2>
<form method="post" action="">
Roll Number: <input type="text" name="rollno" ><br><br>
First Name:&emsp;<input type="text" name="firstname" ><br><br>
Last Name:&emsp;<input type="text" name="lastname" ><br><br>
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
$server = "localhost";
$username = "root";
$password = "";
$dbname = "ass1db";
$con = new mysqli($server,$username,$password,$dbname);
//connection checking here
if ($con->connect_error) {
    die("Connection failed: "
        . $con->connect_error);
}
else{
echo "database connection successful<br>";
}
 

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
$sqlquery = "INSERT INTO student VALUES
    ('$rollno','$firstname','$lastname','$email')";
 
if ($con->query($sqlquery) === TRUE) {
 echo "Record inserted into database successfully";
}
else{
echo "Duplicate Entry entered,Insertion Unsuccessful";
}

}
}
else if($_POST['btn_submit']=="Delete")
{
if(  (empty($rollno))  ||  (empty($firstname))  ||  (empty($lastname))  || (empty($email))        ){
echo "Please fill all fields in the form";
}
else{

echo "You pressed DELETE<br>";

$sqlquery = "DELETE FROM student WHERE rollno='$rollno' AND firstname='$firstname' AND lastname='$lastname' AND email='$email'";
 
if ($con->query($sqlquery) === TRUE) { //thing here is even if not deleted,will return true in delete bcz query is smooth
  if($con->affected_rows>0){
echo "Deleted successfully";
}
else{
echo "Student not Found in the database";
}
}
 else {
  echo "Error occured";
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
$sqlquery = "SELECT * FROM student WHERE rollno='$rollno'";
$result = $con->query($sqlquery);
  
    if ($result->num_rows > 0) 
    {
        while($row = $result->fetch_assoc())  //loop here,fine bcz we are sure that only max 1 tuple is possible
        {
       echo "Roll No: " . $row["rollno"]. ",First name: " . $row["firstname"]. ",Last name: " .  $row["lastname"]. ",Email: " .  $row["email"]. "<br>";
        }
    } 
    else {
        echo "Student details not found";
    }
}
}
else if($_POST['btn_submit']=="Update")
{
if(  (empty($rollno))  ||  (empty($firstname))  ||  (empty($lastname))  || (empty($email))        ){
echo "Please fill all fields in the form";
}
else{
echo "You pressed UPDATE<br>";
$sqlquery = "UPDATE student SET firstname='$firstname',lastname='$lastname',email='$email' WHERE rollno='$rollno'";
$result = $con->query($sqlquery);
  
    if ($con->affected_rows>0) 
    {
         echo "Updated student record successfully";
    } 
    else {
        echo "Student with ".$rollno." as Roll Number does not exist";
    }
}
}
else if($_POST['btn_submit']=="Display")
{
echo "You pressed DISPLAY<br>";
$sqlquery = "SELECT * FROM student";
$result = $con->query($sqlquery);
    if ($result->num_rows > 0) 
    {
        while($row = $result->fetch_assoc())
        {
       echo "Roll No: " . $row["rollno"]. ",First name: " . $row["firstname"]. ",Last name: " .  $row["lastname"].",Email: " .  $row["email"]. "<br>";
        }
    } 
    else {
        echo "No student records found!";
    }
}
}
?>
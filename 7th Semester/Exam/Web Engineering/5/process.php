<?php
$name=$_POST["name"];
$email=$_POST["email"];
$password=$_POST["password"];
$gender=$_POST["gender"];
$message=$_POST["message"];
$department=$_POST["department"];
$interests = isset($_POST['interests'])
 ? implode(",", $_POST['interests'])
 : "";
$conn=mysqli_connect("localhost","root","","studentdb");
$sql="INSERT INTO students
(name,email,password,message,interests,department,gender)
VALUES
('$name','$email','$password','$message','$interests','$department','$gender')";
$result=mysqli_query($conn,$sql);
if($result){
    header("Location: Display.php");
}
else{
    echo "Insert Failed";
}
mysqli_close($conn);
?>
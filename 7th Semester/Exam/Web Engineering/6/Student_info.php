<?php
$roll = $_POST["sid"];
$name = $_POST["fname"];
$m1 = $_POST["ecommerce"];
$m2 = $_POST["graphics"];
$m3 = $_POST["toc"];
$m4 = $_POST["compiler"];
$conn = mysqli_connect("localhost","root","","resultdb");
if(!$conn)
{
    die("Connection Failed");
}
$sql = "INSERT INTO smarks
(roll,name,ecommerce,graphics,toc,compiler)
VALUES
('$roll','$name','$m1','$m2','$m3','$m4')";
if(mysqli_query($conn,$sql))
{
    header("Location: grade_calculation.php");
    exit();
}
else
{
    echo "Insert Failed";
}
mysqli_close($conn);

?>
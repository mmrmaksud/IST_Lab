<?php
$conn=mysqli_connect("localhost","root","","studentdb");
$sql="SELECT * FROM students";
$result=mysqli_query($conn,$sql);
echo "<h2>Student Information</h2>";
echo "
<table border='1' cellspacing='0' cellpadding='10'>
<tr>
<th>Name</th>
<th>Password</th>
<th>Email</th>
<th>Gender</th>
<th>Department</th>
<th>Interests</th>
<th>Message</th>
</tr>";
while($row=mysqli_fetch_assoc($result))
{
    echo "
    <tr>
        <td>{$row['name']}</td>
        <td>{$row['password']}</td>
        <td>{$row['email']}</td>
        <td>{$row['gender']}</td>
        <td>{$row['department']}</td>
        <td>{$row['interests']}</td>
        <td>{$row['message']}</td>
    </tr>";
}
echo "</table>";
mysqli_close($conn);
?>
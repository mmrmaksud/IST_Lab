<?php
$conn = mysqli_connect("localhost","root","","resultdb");
if(!$conn)
{
    die("Connection Failed");
}
$sql = "SELECT * FROM smarks";
$result = mysqli_query($conn,$sql);
echo "
<h2>Student GPA Result</h2>
<table border='1' cellspacing='0' cellpadding='10'>
<tr>
    <th>Name</th>
    <th>Roll</th>
    <th>CGPA</th>
</tr>
";
while($row = mysqli_fetch_assoc($result))
{
    $name = $row["name"];
    $roll = $row["roll"];
    $m1 = $row["ecommerce"];
    $m2 = $row["graphics"];
    $m3 = $row["toc"];
    $m4 = $row["compiler"];
    $g1 = gpa_calculate($m1);
    $g2 = gpa_calculate($m2);
    $g3 = gpa_calculate($m3);
    $g4 = gpa_calculate($m4);
    $cgpa = number_format(($g1+$g2+$g3+$g4)/4,2);
    echo "
    <tr>
        <td>$name</td>
        <td>$roll</td>
        <td>$cgpa</td>
    </tr>
    ";
}
echo "</table>";
function gpa_calculate($marks)
{
    if($marks >= 80) return 4.00;
    elseif($marks >= 76) return 3.75;
    elseif($marks >= 70) return 3.50;
    elseif($marks >= 66) return 3.25;
    elseif($marks >= 60) return 3.00;
    elseif($marks >= 56) return 2.75;
    elseif($marks >= 50) return 2.50;
    elseif($marks >= 46) return 2.25;
    elseif($marks >= 45) return 2.00;
    else return 0.00;
}
mysqli_close($conn);
?>
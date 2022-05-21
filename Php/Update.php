<?php

$servername = "localhost";
$username = "ramen";
$password = "/i-ub4.k@QbsEvf";

$WindowNumber = $GET["window"];
$Open = $GET["open"];

$conn = new mysqli($servername, $username, $password);

$sql = "UPDATE raam.ramen SET open=".$Open."WHERE ID=".$WindowNumber;

if($conn->connect_error) {
  die("Connection failed: ". $conn->connect_error);
}
echo "Connected succesfully";
 ?>

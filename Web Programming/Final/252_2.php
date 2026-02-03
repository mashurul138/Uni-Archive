<?php
$attend = $_POST['attend'];
$cap = $_POST['capacity'];
$price = $_POST['price'];

$screens = ceil($attend / $cap);
$empty = $screens * $cap - $attend;
$wasted = $price * $empty;

echo "Total Screen: $screens <br> ";
echo "Empty Seats: $empty <br> ";
echo "Wasted Money: $wasted <br> ";

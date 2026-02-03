<?php
$attend = $_POST['attend'];
$cost = $_POST['cost'];
$cap = $_POST['capacity'];

$venue = ceil($attend / $cap);
$empty = $venue * $cap - $attend;
$wasted = $empty * $cost;

echo "Total Venue: $venue <br> ";
echo "Empty Seats: $empty <br> ";
echo "Wasted Money: $wasted <br> ";
?>
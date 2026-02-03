<?php
$num = $_POST['num'];
$sps = $_POST['sps'];
$spp = $_POST['spp'];

$total = ceil($num * $sps / $spp);
$left = ($total * $spp) - ($num * $sps);
$wasted = (1050 / $spp) * $left;

echo "Total Pizzas: $total <br> ";
echo "Leftover Slices: $left <br> ";
echo "Wasted Money: $wasted <br> ";

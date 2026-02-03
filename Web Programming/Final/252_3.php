<?php
$host = 'localhost';
$user = 'root';
$pass = '';
$db = 'web';

$conn = new mysqli($host, $user, $pass, $db);
if ($conn->connect_error) {
    die("Connection error");
}

$task1 = $conn->query("SELECT c_id, SUM(revenue) AS Total_Revenue FROM sales_data GROUP BY c_id");

$conn->query("ALTER TABLE sales_data ADD COLUMN IF NOT EXISTS performance VARCHAR(20)");
$conn->query("UPDATE sales_data SET performance = 'Low Performing' WHERE revenue < 40000");
$task2 = $conn->query("SELECT * FROM sales_data WHERE performance IS NOT NULL");

$conn->query("ALTER TABLE sales_data ADD COLUMN IF NOT EXISTS total INT");
$conn->query("UPDATE sales_data SET total = revenue * 1.1 WHERE revenue > 70000");
$task3 = $conn->query("SELECT * FROM sales_data");

$conn->query("ALTER TABLE sales_data ADD COLUMN IF NOT EXISTS rank VARCHAR(20)");
$conn->query("UPDATE sales_data s1 SET rank = 
                CASE 
                    WHEN s1.revenue > (SELECT AVG(s2.revenue) FROM sales_data s2 WHERE s1.c_id = s2.c_id)
                    THEN 'Top Seller'
                    ELSE 'Regular Seller' 
                END");
$task4 = $conn->query("SELECT * FROM sales_data");


?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <h3>Task1: Total Revenue per catagory</h3>
    <table border="1">
        <tr>
            <th>Category ID</th>
            <th>Total Revenue</th>
        </tr>
        <?php while ($row = $task1->fetch_assoc()): ?>
            <tr>
                <td><?= htmlspecialchars($row['c_id']) ?></td>
                <td><?= htmlspecialchars($row['Total_Revenue']) ?></td>
            </tr>
        <?php endwhile; ?>
    </table>

    <h3>Task2: Update catagory</h3>
    <table border="1">
        <tr>
            <th>Product Name</th>
            <th>Category ID</th>
            <th>Category Name</th>
            <th>Performance</th>
        </tr>
        <?php while ($row = $task2->fetch_assoc()): ?>
            <tr>
                <td><?= htmlspecialchars($row['p_name']) ?></td>
                <td><?= htmlspecialchars($row['c_id']) ?></td>
                <td><?= htmlspecialchars($row['c_name']) ?></td>
                <td><?= htmlspecialchars($row['performance']) ?></td>
            </tr>
        <?php endwhile; ?>
    </table>

    <h3>Task3: Update total</h3>
    <table border="1">
        <tr>
            <th>Product Name</th>
            <th>Category ID</th>
            <th>Category Name</th>
            <th>Total</th>
        </tr>
        <?php while ($row = $task3->fetch_assoc()): ?>
            <tr>
                <td><?= htmlspecialchars($row['p_name']) ?></td>
                <td><?= htmlspecialchars($row['c_id']) ?></td>
                <td><?= htmlspecialchars($row['c_name']) ?></td>
                <td><?= htmlspecialchars($row['revenue']) ?></td>
                <td><?= htmlspecialchars($row['total']) ?></td>
            </tr>
        <?php endwhile; ?>
    </table>

    <h3>Task4: Update rank</h3>
    <table border="1">
        <tr>
            <th>Product Name</th>
            <th>Category ID</th>
            <th>Category Name</th>
            <th>Rank</th>
        </tr>
        <?php while ($row = $task4->fetch_assoc()): ?>
            <tr>
                <td><?= htmlspecialchars($row['p_name']) ?></td>
                <td><?= htmlspecialchars($row['c_id']) ?></td>
                <td><?= htmlspecialchars($row['c_name']) ?></td>
                <td><?= htmlspecialchars($row['revenue']) ?></td>
                <td><?= htmlspecialchars($row['rank']) ?></td>
            </tr>
        <?php endwhile; ?>
    </table>

</body>

</html>
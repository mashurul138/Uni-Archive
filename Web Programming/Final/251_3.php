<?php
$host = 'localhost';
$user = 'root';
$pass = '';
$db = 'web';

$conn = new mysqli($host, $user, $pass, $db);
if ($conn->connect_error) {
    die("Connection error" . $conn->connect_error);
}

$employees = $conn->query("SELECT * FROM employee_final");

$task1 = $conn->query("SELECT performance, COUNT(*) AS count FROM employee_final GROUP BY performance");

$conn->query("UPDATE employee_final SET performance = 'C' WHERE salary < 40000 && performance <> 'D'");
$task2 = $conn->query("SELECT * FROM employee_final");

$conn->query("UPDATE employee_final SET salary = salary + 5000 WHERE salary > 50000 AND (salary + 5000) <= 60000");
$task3 = $conn->query("SELECT * FROM employee_final");

$task4 = $conn->query("SELECT d_id, d_name, COUNT(e_id) AS count FROM employee_final GROUP BY d_id, d_name ORDER BY count DESC, e_id ASC");

?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <h3>Task 1: Performance Count</h3>
    <table>
        <tr>
            <th>Performance</th>
            <th>Count</th>
        </tr>
        <?php while ($row = $task1->fetch_assoc()): ?>
            <tr>
                <td><?= htmlspecialchars($row['performance']) ?></td>
                <td><?= htmlspecialchars($row['count']) ?></td>
            </tr>
        <?php endwhile; ?>
    </table>

    <h3>Task 2: Update performance</h3>
    <table>
        <tr>
            <th>Employee id</th>
            <th>Salary</th>
        </tr>
        <?php while ($row = $task2->fetch_assoc()): ?>
            <tr>
                <td><?= htmlspecialchars($row['e_id']) ?></td>
                <td><?= htmlspecialchars($row['performance']) ?></td>
            </tr>
        <?php endwhile; ?>
    </table>

    <h3>Task 3: Update Salary</h3>
    <table>
        <tr>
            <th>Employee id</th>
            <th>Salary</th>
        </tr>
        <?php while ($row = $task3->fetch_assoc()): ?>
            <tr>
                <td><?= htmlspecialchars($row['e_id']) ?></td>
                <td><?= htmlspecialchars($row['salary']) ?></td>
            </tr>
        <?php endwhile; ?>
    </table>

    <h3>Task 4: Employee Count</h3>
    <table>
        <tr>
            <th>Dept Name</th>
            <th>Count</th>
        </tr>
        <?php while ($row = $task4->fetch_assoc()): ?>
            <tr>
                <td><?= htmlspecialchars($row['d_name']) ?></td>
                <td><?= htmlspecialchars($row['count']) ?></td>
            </tr>
        <?php endwhile; ?>
    </table>

</body>

</html>
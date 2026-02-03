<?php
$host = 'localhost';
$user = 'root';
$pass = '';
$db = 'web';

$conn = new mysqli($host, $user, $pass, $db);
if ($conn->connect_error) {
    die("COnnection Erorr: " . $conn->connect_error);
}

$students = $conn->query("SELECT * FROM student_final");

if (!$conn->query("UPDATE student_final SET lettergrade='C' WHERE grade < 75 AND lettergrade <> 'D'")) {
    die("Letter Grade update failure");
}

if (!$conn->query("UPDATE student_final SET grade= grade + 5 WHERE grade > 80 AND (grade  + 5) <= 90")) {
    die("Grade update failure");
}

$updated = $conn->query("SELECT * FROM student_final");

$res =  $conn->query("SELECT c_id, c_title, COUNT(st_id) AS count FROM student_final 
GROUP BY c_id, c_title ORDER BY count DESC, c_id ASC");
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <h3>Before Update</h3>
    <table border="1">
        <tr>
            <th>Student ID</th>
            <th>Student Name</th>
            <th>Course ID</th>
            <th>Course Title</th>
            <th>Grade</th>
            <th>Letter Grade</th>
        </tr>


        <?php while ($row = $students->fetch_assoc()): ?>
            <tr>
                <td><?= htmlspecialchars($row['st_id']) ?></td>
                <td><?= htmlspecialchars($row['st_name']) ?></td>
                <td><?= htmlspecialchars($row['c_id']) ?></td>
                <td><?= htmlspecialchars($row['c_title']) ?></td>
                <td><?= htmlspecialchars($row['grade']) ?></td>
                <td><?= htmlspecialchars($row['lettergrade']) ?></td>
            </tr>
        <?php endwhile; ?>
    </table>

    <h3>After Update</h3>
    <table border="1">
        <tr>
            <th>Student ID</th>
            <th>Student Name</th>
            <th>Course ID</th>
            <th>Course Title</th>
            <th>Grade</th>
            <th>Letter Grade</th>
        </tr>
        <?php while ($row = $updated->fetch_assoc()): ?>
            <tr>
                <td><?= htmlspecialchars($row['st_id']) ?></td>
                <td><?= htmlspecialchars($row['st_name']) ?></td>
                <td><?= htmlspecialchars($row['c_id']) ?></td>
                <td><?= htmlspecialchars($row['c_title']) ?></td>
                <td><?= htmlspecialchars($row['grade']) ?></td>
                <td><?= htmlspecialchars($row['lettergrade']) ?></td>
            </tr>
        <?php endwhile; ?>
    </table>

    <h3>Student per course</h3>
    <table border="1">
        <tr>
            <th>Course ID</th>
            <th>Course Title</th>
            <th>Count</th>
        </tr>
        <?php while ($r = $res->fetch_assoc()): ?>
            <tr>
                <td><?= $r['c_id'] ?></td>
                <td><?= $r['c_title'] ?></td>
                <td><?= $r['count'] ?></td>
            </tr>
        <?php endwhile; ?>
    </table>
</body>

</html>
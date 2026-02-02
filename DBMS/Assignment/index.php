<?php
$host = 'localhost';
$user = 'root';
$pass = '';
$db   = 'todos';

$conn = new mysqli($host, $user, $pass, $db);
if ($conn->connect_error) {
    die('Connection failed: ' . $conn->connect_error);
}

$sql = "CREATE TABLE IF NOT EXISTS tasks (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    due_date VARCHAR(20) NOT NULL,
    status VARCHAR(20) NOT NULL DEFAULT 'Pending'
)";

if (!$conn->query($sql)) {
    die('Table error: ' . $conn->error);
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') {

    if (isset($_POST['add'])) {
        $name = $conn->real_escape_string(trim($_POST['task_name']));
        $due  = $conn->real_escape_string(trim($_POST['due_date']));
        $conn->query("INSERT INTO tasks (name, due_date, status) VALUES ('$name', '$due', 'Pending')");
    }

    if (isset($_POST['remove'])) {
        $id = (int)($_POST['task_id'] ?? 0);
        if ($id > 0) {
            $conn->query("DELETE FROM tasks WHERE id = $id");
        }
    }

    $conn->close();
    header('Location: index.php');
    exit();
}

$tasks = $conn->query('SELECT * FROM tasks ORDER BY id ASC');
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Todo list</title>
    <style>
        table,
        th,
        td {
            border: 1px solid cyan;
            border-radius: 10px;
            padding: 10px;
        }
    </style>
</head>

<body>
    <h1>Tasks</h1>
    <table>
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Due time</th>
            <th>Status</th>
        </tr>

        <?php while ($row = $tasks->fetch_assoc()): ?>
            <tr>
                <td><?= htmlspecialchars($row['id']) ?></td>
                <td><?= htmlspecialchars($row['name']) ?></td>
                <td><?= htmlspecialchars($row['due_date']) ?></td>
                <td><?= htmlspecialchars($row['status']) ?></td>
            </tr>
        <?php endwhile; ?>
    </table>

    <h1>Add a new task</h1>
    <form action="index.php" method="post">
        <label>Task name:</label><br>
        <input type="text" name="task_name" required><br>
        <label>Due date:</label><br>
        <input type="text" name="due_date" required><br><br>
        <input type="submit" name="add" value="Add">
    </form>

    <h1>Remove a task</h1>
    <form action="index.php" method="post">
        <label>Task ID:</label><br>
        <input type="text" name="task_id" required><br><br>
        <input type="submit" name="remove" value="Remove">
    </form>
</body>

</html>
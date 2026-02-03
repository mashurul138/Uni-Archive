# Web Programming Final - Run Guide (XAMPP)

These files were developed for XAMPP with PHP + MySQL (MariaDB).

## 1) Requirements
- XAMPP installed (Apache + MySQL)
- A browser

## 2) Put project files in `htdocs`
1. Open your XAMPP install folder (usually `C:\xampp`).
2. Copy this `Final` folder into `C:\xampp\htdocs\`.
3. Final path should be:
   `C:\xampp\htdocs\final\`

## 3) Start services
1. Open **XAMPP Control Panel**.
2. Start **Apache** and **MySQL**.

## 4) Import database
1. Open `http://localhost/phpmyadmin`.
2. Click **Import**.
3. Choose file: `web.sql` (from this project folder).
4. Click **Go**.

`web.sql` creates database `web` and all required tables/data.

## 5) Open in browser
Use these URLs:

### HTML + calculation tasks
- `http://localhost/final/243_2.html`
- `http://localhost/final/251_2.html`
- `http://localhost/final/252_2.html`

### Database tasks
- `http://localhost/final/243_3.php`
- `http://localhost/final/251_3.php`
- `http://localhost/final/252_3.php`

## 6) Default DB config used in PHP
All PHP DB files use:
- Host: `localhost`
- User: `root`
- Password: *(empty)*
- Database: `web`

If your MySQL username/password is different, update it in:
- `243_3.php`
- `251_3.php`
- `252_3.php`

## Troubleshooting
- **Database/connection error:** check MySQL is running and credentials match your setup.
- **Table/data changed after multiple runs:** some scripts update rows. Re-import `web.sql` to reset.
- **404 page not found:** confirm folder name is exactly `final` inside `htdocs`.

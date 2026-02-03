-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Feb 04, 2026 at 12:02 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `web`
--

-- --------------------------------------------------------

--
-- Table structure for table `employee_final`
--

CREATE TABLE `employee_final` (
  `e_id` int(11) NOT NULL,
  `e_name` varchar(50) NOT NULL,
  `d_id` int(11) NOT NULL,
  `d_name` varchar(50) NOT NULL,
  `salary` int(11) NOT NULL,
  `performance` varchar(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `employee_final`
--

INSERT INTO `employee_final` (`e_id`, `e_name`, `d_id`, `d_name`, `salary`, `performance`) VALUES
(1, 'arif', 201, 'software development', 45000, 'B'),
(2, 'marium', 201, 'software development', 57000, 'A'),
(3, 'sabbir', 202, 'quality assurance', 38000, 'C'),
(4, 'samira', 203, 'UI UX design', 42000, 'B');

-- --------------------------------------------------------

--
-- Table structure for table `sales_data`
--

CREATE TABLE `sales_data` (
  `s_id` int(11) NOT NULL,
  `p_name` varchar(50) NOT NULL,
  `c_id` int(11) NOT NULL,
  `c_name` varchar(50) NOT NULL,
  `quantity` int(11) NOT NULL,
  `revenue` int(11) NOT NULL,
  `performance` varchar(20) DEFAULT NULL,
  `total` int(11) DEFAULT NULL,
  `rank` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `sales_data`
--

INSERT INTO `sales_data` (`s_id`, `p_name`, `c_id`, `c_name`, `quantity`, `revenue`, `performance`, `total`, `rank`) VALUES
(1, 'laptop', 301, 'electronics', 5, 350000, NULL, 385000, 'Top Seller'),
(2, 'mouse', 301, 'electronics', 15, 45000, NULL, NULL, 'Regular Seller'),
(3, 'chair', 302, 'furniture', 8, 64000, NULL, NULL, 'Regular Seller'),
(4, 'desk', 302, 'furniture', 6, 72000, NULL, 79200, 'Top Seller'),
(5, 'bottle', 303, 'accessories', 20, 30000, 'Low Performing', NULL, 'Top Seller'),
(6, 'pen', 303, 'accessories', 25, 20000, 'Low Performing', NULL, 'Regular Seller');

-- --------------------------------------------------------

--
-- Table structure for table `student_final`
--

CREATE TABLE `student_final` (
  `st_id` int(11) NOT NULL,
  `st_name` varchar(50) NOT NULL,
  `c_id` int(11) NOT NULL,
  `c_title` varchar(50) NOT NULL,
  `grade` int(11) NOT NULL,
  `lettergrade` varchar(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `student_final`
--

INSERT INTO `student_final` (`st_id`, `st_name`, `c_id`, `c_title`, `grade`, `lettergrade`) VALUES
(1, 'karim', 101, 'web', 90, 'B'),
(2, 'rahim', 101, 'web', 92, 'A'),
(3, 'jashim', 102, 'project', 78, 'C'),
(4, 'jasica', 101, 'web', 65, 'C'),
(5, 'faria', 102, 'project', 95, 'A'),
(6, 'niassoh', 103, 'system', 80, 'B');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `employee_final`
--
ALTER TABLE `employee_final`
  ADD PRIMARY KEY (`e_id`);

--
-- Indexes for table `sales_data`
--
ALTER TABLE `sales_data`
  ADD PRIMARY KEY (`s_id`);

--
-- Indexes for table `student_final`
--
ALTER TABLE `student_final`
  ADD PRIMARY KEY (`st_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `student_final`
--
ALTER TABLE `student_final`
  MODIFY `st_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

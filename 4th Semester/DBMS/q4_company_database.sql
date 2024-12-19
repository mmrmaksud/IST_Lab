-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: May 24, 2024 at 09:02 PM
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
-- Database: `q4_company_database`
--

-- --------------------------------------------------------

--
-- Table structure for table `company`
--

CREATE TABLE `company` (
  `company_name` varchar(100) NOT NULL,
  `city` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `company`
--

INSERT INTO `company` (`company_name`, `city`) VALUES
('First Bank Corporation', 'Los Angeles'),
('IFIC Bank Ltd', 'New York'),
('Second Company', 'Chicago');

-- --------------------------------------------------------

--
-- Table structure for table `employee`
--

CREATE TABLE `employee` (
  `employee_name` varchar(50) NOT NULL,
  `street` varchar(100) DEFAULT NULL,
  `city` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `employee`
--

INSERT INTO `employee` (`employee_name`, `street`, `city`) VALUES
('Alice Smith', '456 Elm St', 'Los Angeles'),
('Bob Johnson', '789 Oak St', 'Chicago'),
('John Doe', '123 Main St', 'New York');

-- --------------------------------------------------------

--
-- Table structure for table `manages`
--

CREATE TABLE `manages` (
  `employee_name` varchar(50) NOT NULL,
  `manages_name` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `manages`
--

INSERT INTO `manages` (`employee_name`, `manages_name`) VALUES
('Alice Smith', 'Bob Johnson');

-- --------------------------------------------------------

--
-- Table structure for table `works`
--

CREATE TABLE `works` (
  `employee_name` varchar(50) NOT NULL,
  `company_name` varchar(100) NOT NULL,
  `salary` decimal(10,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `works`
--

INSERT INTO `works` (`employee_name`, `company_name`, `salary`) VALUES
('Alice Smith', 'First Bank Corporation', 60000.00),
('Bob Johnson', 'Second Company', 55000.00),
('John Doe', 'IFIC Bank Ltd', 50000.00);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `company`
--
ALTER TABLE `company`
  ADD PRIMARY KEY (`company_name`);

--
-- Indexes for table `employee`
--
ALTER TABLE `employee`
  ADD PRIMARY KEY (`employee_name`);

--
-- Indexes for table `manages`
--
ALTER TABLE `manages`
  ADD PRIMARY KEY (`employee_name`),
  ADD KEY `manages_name` (`manages_name`);

--
-- Indexes for table `works`
--
ALTER TABLE `works`
  ADD PRIMARY KEY (`employee_name`,`company_name`),
  ADD KEY `company_name` (`company_name`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `manages`
--
ALTER TABLE `manages`
  ADD CONSTRAINT `manages_ibfk_1` FOREIGN KEY (`employee_name`) REFERENCES `employee` (`employee_name`),
  ADD CONSTRAINT `manages_ibfk_2` FOREIGN KEY (`manages_name`) REFERENCES `employee` (`employee_name`);

--
-- Constraints for table `works`
--
ALTER TABLE `works`
  ADD CONSTRAINT `works_ibfk_1` FOREIGN KEY (`employee_name`) REFERENCES `employee` (`employee_name`),
  ADD CONSTRAINT `works_ibfk_2` FOREIGN KEY (`company_name`) REFERENCES `company` (`company_name`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

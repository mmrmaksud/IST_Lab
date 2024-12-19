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
-- Database: `q1_bank_database`
--

-- --------------------------------------------------------

--
-- Table structure for table `account`
--

CREATE TABLE `account` (
  `account_number` int(11) NOT NULL,
  `branch_name` varchar(50) DEFAULT NULL,
  `balance` decimal(12,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `account`
--

INSERT INTO `account` (`account_number`, `branch_name`, `balance`) VALUES
(101, 'Perryridge', 5000.00),
(102, 'Brighton', 10000.00),
(103, 'Downtown', 7500.00),
(104, 'Perryridge', 200.00);

-- --------------------------------------------------------

--
-- Table structure for table `borrower`
--

CREATE TABLE `borrower` (
  `customer_name` varchar(50) NOT NULL,
  `loan_number` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `borrower`
--

INSERT INTO `borrower` (`customer_name`, `loan_number`) VALUES
('Alice', 1),
('Bob', 2),
('Charlie', 3),
('David', 4);

-- --------------------------------------------------------

--
-- Table structure for table `branch`
--

CREATE TABLE `branch` (
  `branch_name` varchar(50) NOT NULL,
  `branch_city` varchar(50) DEFAULT NULL,
  `assets` decimal(12,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `branch`
--

INSERT INTO `branch` (`branch_name`, `branch_city`, `assets`) VALUES
('Brighton', 'New York', 200000.00),
('Downtown', 'Brooklyn', 100000.00),
('Perryridge', 'Brooklyn', 150000.00);

-- --------------------------------------------------------

--
-- Table structure for table `customer`
--

CREATE TABLE `customer` (
  `customer_name` varchar(50) NOT NULL,
  `customer_street` varchar(100) DEFAULT NULL,
  `customer_city` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `customer`
--

INSERT INTO `customer` (`customer_name`, `customer_street`, `customer_city`) VALUES
('Alice', '123 Main St', 'Brooklyn'),
('Bob', '456 Elm St', 'New York'),
('Charlie', '789 Oak St', 'Brooklyn'),
('David', '101 Pine St', 'Brooklyn');

-- --------------------------------------------------------

--
-- Table structure for table `depositor`
--

CREATE TABLE `depositor` (
  `customer_name` varchar(50) NOT NULL,
  `account_number` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `depositor`
--

INSERT INTO `depositor` (`customer_name`, `account_number`) VALUES
('Alice', 101),
('Bob', 102),
('Charlie', 103),
('David', 104);

-- --------------------------------------------------------

--
-- Table structure for table `loan`
--

CREATE TABLE `loan` (
  `loan_number` int(11) NOT NULL,
  `branch_name` varchar(50) DEFAULT NULL,
  `amount` decimal(12,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `loan`
--

INSERT INTO `loan` (`loan_number`, `branch_name`, `amount`) VALUES
(1, 'Perryridge', 20000.00),
(2, 'Brighton', 30000.00),
(3, 'Downtown', 15000.00),
(4, 'Perryridge', 1000.00);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `account`
--
ALTER TABLE `account`
  ADD PRIMARY KEY (`account_number`),
  ADD KEY `branch_name` (`branch_name`);

--
-- Indexes for table `borrower`
--
ALTER TABLE `borrower`
  ADD PRIMARY KEY (`customer_name`,`loan_number`),
  ADD KEY `loan_number` (`loan_number`);

--
-- Indexes for table `branch`
--
ALTER TABLE `branch`
  ADD PRIMARY KEY (`branch_name`);

--
-- Indexes for table `customer`
--
ALTER TABLE `customer`
  ADD PRIMARY KEY (`customer_name`);

--
-- Indexes for table `depositor`
--
ALTER TABLE `depositor`
  ADD PRIMARY KEY (`customer_name`,`account_number`),
  ADD KEY `account_number` (`account_number`);

--
-- Indexes for table `loan`
--
ALTER TABLE `loan`
  ADD PRIMARY KEY (`loan_number`),
  ADD KEY `branch_name` (`branch_name`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `account`
--
ALTER TABLE `account`
  ADD CONSTRAINT `account_ibfk_1` FOREIGN KEY (`branch_name`) REFERENCES `branch` (`branch_name`);

--
-- Constraints for table `borrower`
--
ALTER TABLE `borrower`
  ADD CONSTRAINT `borrower_ibfk_1` FOREIGN KEY (`customer_name`) REFERENCES `customer` (`customer_name`),
  ADD CONSTRAINT `borrower_ibfk_2` FOREIGN KEY (`loan_number`) REFERENCES `loan` (`loan_number`);

--
-- Constraints for table `depositor`
--
ALTER TABLE `depositor`
  ADD CONSTRAINT `depositor_ibfk_1` FOREIGN KEY (`customer_name`) REFERENCES `customer` (`customer_name`),
  ADD CONSTRAINT `depositor_ibfk_2` FOREIGN KEY (`account_number`) REFERENCES `account` (`account_number`);

--
-- Constraints for table `loan`
--
ALTER TABLE `loan`
  ADD CONSTRAINT `loan_ibfk_1` FOREIGN KEY (`branch_name`) REFERENCES `branch` (`branch_name`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

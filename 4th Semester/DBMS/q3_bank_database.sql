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
-- Database: `q3_bank_database`
--

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
('Alice Johnson', 3),
('Alice Johnson', 5),
('Bob Williams', 4),
('Jane Doe', 2),
('John Smith', 1);

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
('Downtown Branch', 'New York', 750000.00),
('Eastside Branch', 'Los Angeles', 600000.00),
('Main Branch', 'New York', 1000000.00),
('Uptown Branch', 'New York', 500000.00),
('Westside Branch', 'Los Angeles', 900000.00);

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
('Alice Johnson', '789 Oak St', 'New York'),
('Bob Williams', '101 Pine St', 'Los Angeles'),
('Jane Doe', '456 Elm St', 'Los Angeles'),
('John Smith', '123 Main St', 'New York');

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
('Alice Johnson', 103),
('Alice Johnson', 105),
('Bob Williams', 104),
('Jane Doe', 102),
('John Smith', 101);

-- --------------------------------------------------------

--
-- Table structure for table `loan_account`
--

CREATE TABLE `loan_account` (
  `loan_number` int(11) NOT NULL,
  `branch_name` varchar(50) DEFAULT NULL,
  `amount` decimal(12,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `loan_account`
--

INSERT INTO `loan_account` (`loan_number`, `branch_name`, `amount`) VALUES
(1, 'Main Branch', 50000.00),
(2, 'Downtown Branch', 30000.00),
(3, 'Uptown Branch', 20000.00),
(4, 'Westside Branch', 40000.00),
(5, 'Eastside Branch', 25000.00);

-- --------------------------------------------------------

--
-- Table structure for table `saving_account`
--

CREATE TABLE `saving_account` (
  `account_number` int(11) NOT NULL,
  `branch_name` varchar(50) DEFAULT NULL,
  `balance` decimal(12,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `saving_account`
--

INSERT INTO `saving_account` (`account_number`, `branch_name`, `balance`) VALUES
(101, 'Main Branch', 10000.00),
(102, 'Downtown Branch', 15000.00),
(103, 'Uptown Branch', 20000.00),
(104, 'Westside Branch', 30000.00),
(105, 'Eastside Branch', 5000.00);

--
-- Indexes for dumped tables
--

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
-- Indexes for table `loan_account`
--
ALTER TABLE `loan_account`
  ADD PRIMARY KEY (`loan_number`),
  ADD KEY `branch_name` (`branch_name`);

--
-- Indexes for table `saving_account`
--
ALTER TABLE `saving_account`
  ADD PRIMARY KEY (`account_number`),
  ADD KEY `branch_name` (`branch_name`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `borrower`
--
ALTER TABLE `borrower`
  ADD CONSTRAINT `borrower_ibfk_1` FOREIGN KEY (`customer_name`) REFERENCES `customer` (`customer_name`),
  ADD CONSTRAINT `borrower_ibfk_2` FOREIGN KEY (`loan_number`) REFERENCES `loan_account` (`loan_number`);

--
-- Constraints for table `depositor`
--
ALTER TABLE `depositor`
  ADD CONSTRAINT `depositor_ibfk_1` FOREIGN KEY (`customer_name`) REFERENCES `customer` (`customer_name`),
  ADD CONSTRAINT `depositor_ibfk_2` FOREIGN KEY (`account_number`) REFERENCES `saving_account` (`account_number`);

--
-- Constraints for table `loan_account`
--
ALTER TABLE `loan_account`
  ADD CONSTRAINT `loan_account_ibfk_1` FOREIGN KEY (`branch_name`) REFERENCES `branch` (`branch_name`);

--
-- Constraints for table `saving_account`
--
ALTER TABLE `saving_account`
  ADD CONSTRAINT `saving_account_ibfk_1` FOREIGN KEY (`branch_name`) REFERENCES `branch` (`branch_name`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: May 24, 2024 at 09:06 PM
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
-- Database: `q5_car_insurance_database`
--

-- --------------------------------------------------------

--
-- Table structure for table `accident`
--

CREATE TABLE `accident` (
  `report_number` int(11) NOT NULL,
  `date` date DEFAULT NULL,
  `location` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `accident`
--

INSERT INTO `accident` (`report_number`, `date`, `location`) VALUES
(100, '2020-05-20', 'Downtown'),
(101, '2021-07-15', 'Uptown');

-- --------------------------------------------------------

--
-- Table structure for table `car`
--

CREATE TABLE `car` (
  `license` varchar(20) NOT NULL,
  `model` varchar(50) DEFAULT NULL,
  `year` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `car`
--

INSERT INTO `car` (`license`, `model`, `year`) VALUES
('DHAKA 1000', 'Toyota', 2018),
('DHAKA 2000', 'Honda', 2019);

-- --------------------------------------------------------

--
-- Table structure for table `owns`
--

CREATE TABLE `owns` (
  `driver_id` int(11) NOT NULL,
  `license` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `owns`
--

INSERT INTO `owns` (`driver_id`, `license`) VALUES
(1, 'DHAKA 1000'),
(2, 'DHAKA 2000');

-- --------------------------------------------------------

--
-- Table structure for table `participate`
--

CREATE TABLE `participate` (
  `driver_id` int(11) NOT NULL,
  `car` varchar(20) NOT NULL,
  `report_number` int(11) NOT NULL,
  `damage_amount` decimal(10,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `participate`
--

INSERT INTO `participate` (`driver_id`, `car`, `report_number`, `damage_amount`) VALUES
(1, 'DHAKA 1000', 100, 5000.00),
(2, 'DHAKA 2000', 101, 3000.00);

-- --------------------------------------------------------

--
-- Table structure for table `person`
--

CREATE TABLE `person` (
  `driver_id` int(11) NOT NULL,
  `name` varchar(100) DEFAULT NULL,
  `address` varchar(200) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `person`
--

INSERT INTO `person` (`driver_id`, `name`, `address`) VALUES
(1, 'Simanto', '123 Main St'),
(2, 'John Doe', '456 Elm St');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `accident`
--
ALTER TABLE `accident`
  ADD PRIMARY KEY (`report_number`);

--
-- Indexes for table `car`
--
ALTER TABLE `car`
  ADD PRIMARY KEY (`license`);

--
-- Indexes for table `owns`
--
ALTER TABLE `owns`
  ADD PRIMARY KEY (`driver_id`,`license`),
  ADD KEY `license` (`license`);

--
-- Indexes for table `participate`
--
ALTER TABLE `participate`
  ADD PRIMARY KEY (`driver_id`,`car`,`report_number`),
  ADD KEY `car` (`car`),
  ADD KEY `report_number` (`report_number`);

--
-- Indexes for table `person`
--
ALTER TABLE `person`
  ADD PRIMARY KEY (`driver_id`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `owns`
--
ALTER TABLE `owns`
  ADD CONSTRAINT `owns_ibfk_1` FOREIGN KEY (`driver_id`) REFERENCES `person` (`driver_id`),
  ADD CONSTRAINT `owns_ibfk_2` FOREIGN KEY (`license`) REFERENCES `car` (`license`);

--
-- Constraints for table `participate`
--
ALTER TABLE `participate`
  ADD CONSTRAINT `participate_ibfk_1` FOREIGN KEY (`driver_id`) REFERENCES `person` (`driver_id`),
  ADD CONSTRAINT `participate_ibfk_2` FOREIGN KEY (`car`) REFERENCES `car` (`license`),
  ADD CONSTRAINT `participate_ibfk_3` FOREIGN KEY (`report_number`) REFERENCES `accident` (`report_number`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

/*
 Navicat Premium Data Transfer

 Source Server         : MySQLlocal
 Source Server Type    : MySQL
 Source Server Version : 80013
 Source Host           : localhost:3306
 Source Schema         : salesystem

 Target Server Type    : MySQL
 Target Server Version : 80013
 File Encoding         : 65001

 Date: 21/12/2018 12:58:58
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for log
-- ----------------------------
DROP TABLE IF EXISTS `log`;
CREATE TABLE `log`  (
  `time` datetime(6) NOT NULL ON UPDATE CURRENT_TIMESTAMP(6),
  `usrname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `did` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (`time`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for sale
-- ----------------------------
DROP TABLE IF EXISTS `sale`;
CREATE TABLE `sale`  (
  `time` datetime(6) NOT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `num` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `shape` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `color` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `closeway` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `material` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `size` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (`time`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of sale
-- ----------------------------
INSERT INTO `sale` VALUES ('2018-12-18 12:13:44.000000', '3', '3', '3', '3', '3', '3', '3');

-- ----------------------------
-- Table structure for stock
-- ----------------------------
DROP TABLE IF EXISTS `stock`;
CREATE TABLE `stock`  (
  `time` datetime(6) NOT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `rest` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `shape` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `color` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `closeway` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `material` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `size` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (`time`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of stock
-- ----------------------------
INSERT INTO `stock` VALUES ('2018-12-21 12:56:37.000000', '1', '2', '3', '4', '5', '6', '7');

-- ----------------------------
-- Table structure for user
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user`  (
  `username` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `password` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `competence` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (`username`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of user
-- ----------------------------
INSERT INTO `user` VALUES ('1', '1', 'MANAGE');
INSERT INTO `user` VALUES ('2', '2', 'USER');
INSERT INTO `user` VALUES ('3', '3', 'MANAGE');
INSERT INTO `user` VALUES ('5', '5', 'USER');
INSERT INTO `user` VALUES ('6', '5', 'MANAGE');
INSERT INTO `user` VALUES ('root', 'root', 'MANAGE');

SET FOREIGN_KEY_CHECKS = 1;

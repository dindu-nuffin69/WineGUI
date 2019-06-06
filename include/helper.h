/**
 * Copyright (c) 2019 WineGUI
 *
 * \file    helper.h
 * \brief   Helper CLI class
 * \author  Melroy van den Berg <webmaster1989@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include <fstream>
#include <ctime>
#include <iomanip>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <filesystem>
#include <string>
#include <cstring>
#include <array>
#include <vector>

#include "bottle_types.h"


/**
 * \class Helper
 * \brief Provide some helper methods for CLI interaction
 */
class Helper
{
public:
  static string retrieveName(string prefix_path);
  static string retrieveWindowsOSVersion(string prefix_path);
  static BottleTypes::Bit retrieveSystemBit(string prefix_path);
  static BottleTypes::AudioDriver retrieveAudioDriver(string prefix_path);
  static string retrieveVirtualDesktop(string prefix_path);
  static string retrieveLastWineUpdate(string prefix_path);
  static bool retrieveWineStatus(string prefix_path);
  static string retrieveCLetterDrive(string prefix_path);
  static string retrieveWineVersion();
private:
  static string exec(const char* cmd);
  static void setWinePrefix(string prefix_path);
  static void removeWinePrefix();
  static std::vector<string> readFile(string file_path);
  static std::vector<string> split(const string& s, char delimiter);
};

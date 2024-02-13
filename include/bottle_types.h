/**
 * Copyright (c) 2019-2023 WineGUI
 *
 * \file    bottle_types.h
 * \brief   Bottle type enum definitions (like Windows OS, audio drivers, supported Windows list)
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

#include <glibmm/ustring.h>
#include <string>
#include <vector>

/**
 * \brief Bottle type enum definitions
 */
namespace BottleTypes
{
  /**
   * \enum Windows
   * \brief List of Windows versions.
   * \note Don't forget to update the to_string methods if required!
   * \note Don't forget to update WindowsVersions struct in helper.cc
   */
  enum class Windows
  {
    Windows20 = 0,
    Windows30,
    Windows31,
    WindowsNT351,
    WindowsNT40,
    Windows95,
    Windows98,
    WindowsME,
    Windows2000,
    WindowsXP,
    Windows2003,
    WindowsVista,
    Windows2008,
    Windows7,
    Windows2008R2,
    Windows8,
    Windows81,
    Windows10,
    Windows11
  };

  /**
   * \enum Bit
   * \brief Windows bit options
   */
  enum class Bit
  {
    win32,
    win64
  };

  typedef std::pair<Windows, Bit> WindowsAndBit; /*!< Windows + Bit pair, used within the list of supported Windows versions */

  /**
   * \brief Supported list of Windows version with their bit support
   */
  inline std::vector<WindowsAndBit> SupportedWindowsVersions = {
      std::pair(Windows::Windows20, Bit::win32),    std::pair(Windows::Windows30, Bit::win32),     std::pair(Windows::Windows31, Bit::win32),
      std::pair(Windows::WindowsNT351, Bit::win32), std::pair(Windows::WindowsNT40, Bit::win32),   std::pair(Windows::Windows95, Bit::win32),
      std::pair(Windows::Windows98, Bit::win32),    std::pair(Windows::WindowsME, Bit::win32),     std::pair(Windows::Windows2000, Bit::win32),
      std::pair(Windows::WindowsXP, Bit::win32),    std::pair(Windows::WindowsXP, Bit::win64),     std::pair(Windows::Windows2003, Bit::win32),
      std::pair(Windows::Windows2003, Bit::win64),  std::pair(Windows::WindowsVista, Bit::win32),  std::pair(Windows::WindowsVista, Bit::win64),
      std::pair(Windows::Windows2008, Bit::win32),  std::pair(Windows::Windows2008, Bit::win64),   std::pair(Windows::Windows7, Bit::win32),
      std::pair(Windows::Windows7, Bit::win64),     std::pair(Windows::Windows2008R2, Bit::win32), std::pair(Windows::Windows2008R2, Bit::win64),
      std::pair(Windows::Windows8, Bit::win32),     std::pair(Windows::Windows8, Bit::win64),      std::pair(Windows::Windows81, Bit::win32),
      std::pair(Windows::Windows81, Bit::win64),    std::pair(Windows::Windows10, Bit::win32),     std::pair(Windows::Windows10, Bit::win64),
      std::pair(Windows::Windows11, Bit::win32),    std::pair(Windows::Windows11, Bit::win64),
  };

  //// Default Windows version (Windows 10 32-bit) as WineGUI Bottle
  static const int DefaultBottleIndex = 25;

  /**
   * \enum AudioDriver
   * \brief Wine supported audio drivers
   */
  enum class AudioDriver
  {
    pulseaudio = 0,
    alsa,
    coreaudio,
    oss,
    disabled
  };

  //// Enum AudioDriver Start iterator
  static const int AudioDriverStart = (int)AudioDriver::pulseaudio;
  //// Enum AudioDriver End iterator
  static const int AudioDriverEnd = (int)AudioDriver::disabled + 1;

  //// Default AudioDriver for WineGui Bottle
  static const int DefaultAudioDriverIndex = (int)AudioDriver::pulseaudio;

  // Bit enum to string
  inline static Glib::ustring to_string(Bit bit)
  {
    switch (bit)
    {
    case Bit::win32:
      return "32-bit";
    case Bit::win64:
      return "64-bit";
    default:
      return "- Unknown OS bit -";
    }
  }

  // Windows enum to string
  // TODO: Move the helper.cc windows list to bottle_types,
  // in order to have a single point of definition of Windows names
  inline static Glib::ustring to_string(Windows win)
  {
    switch (win)
    {
    case Windows::Windows20:
      return "Windows 2.0";
    case Windows::Windows30:
      return "Windows 3.0";
    case Windows::Windows31:
      return "Windows 3.1";
    case Windows::WindowsNT351:
      return "Windows NT 3.51";
    case Windows::WindowsNT40:
      return "Windows NT 4.0";
    case Windows::Windows95:
      return "Windows 95";
    case Windows::Windows98:
      return "Windows 98";
    case Windows::WindowsME:
      return "Windows ME";
    case Windows::Windows2000:
      return "Windows 2000";
    case Windows::WindowsXP:
      return "Windows XP";
    case Windows::Windows2003:
      return "Windows 2003";
    case Windows::WindowsVista:
      return "Windows Vista";
    case Windows::Windows2008:
      return "Windows 2008";
    case Windows::Windows7:
      return "Windows 7";
    case Windows::Windows2008R2:
      return "Windows 2008 R2";
    case Windows::Windows8:
      return "Windows 8";
    case Windows::Windows81:
      return "Windows 8.1";
    case Windows::Windows10:
      return "Windows 10";
    case Windows::Windows11:
      return "Windows 11";
    default:
      return "- Unknown Windows OS -";
    }
  }

  // Debug log level to string
  inline static Glib::ustring debug_log_level_to_string(int log_level)
  {
    switch (log_level)
    {
    case 0:
      return "Off";
    case 1:
      return "Default";
    case 2:
      return "Only errors (Could improve performance)";
    case 3:
      return "Also log warnings (Recommended for debugging)";
    case 4:
      return "Log frames per seconds";
    case 5:
      return "Disable D3D/GL messages (Could improve performance)";
    case 6:
      return "Relay + Heap";
    case 7:
      return "Relay + Message box";
    case 8:
      return "All except relay (too verbose!)";
    case 9:
      return "All (too verbose!)";
    default:
      return "- Unknown Log Level -";
    }
  }

  /**
   * Get Winetricks Windows OS version string
   * \return std::string (since it's not used in GTK GUI)
   */
  inline static std::string get_winetricks_string(Windows win)
  {
    switch (win)
    {
    case Windows::Windows20:
      return "win20";
    case Windows::Windows30:
      return "win30";
    case Windows::Windows31:
      return "win31";
    case Windows::WindowsNT351:
      return "nt351";
    case Windows::WindowsNT40:
      return "nt40";
    case Windows::Windows95:
      return "win95";
    case Windows::Windows98:
      return "win98";
    case Windows::WindowsME:
      return "winme";
    case Windows::Windows2000:
      return "win2k";
    case Windows::WindowsXP:
      return "winxp";
    case Windows::Windows2003:
      return "win2k3";
    case Windows::WindowsVista:
      return "vista";
    case Windows::Windows2008:
      return "win2k8";
    case Windows::Windows7:
      return "win7";
    case Windows::Windows2008R2:
      return "win2k8r2";
    case Windows::Windows8:
      return "win8";
    case Windows::Windows81:
      return "win81";
    case Windows::Windows10:
      return "win10";
    case Windows::Windows11:
      return "win11";
    default:
      return "win7";
    }
  }

  // AudioDriver enum to string
  inline static Glib::ustring to_string(AudioDriver audio)
  {
    switch (audio)
    {
    case AudioDriver::pulseaudio:
      return "PulseAudio";
    case AudioDriver::alsa:
      return "Advanced Linux Sound Architecture (ALSA)";
    case AudioDriver::coreaudio:
      return "Mac Core Audio";
    case AudioDriver::oss:
      return "Open Sound System (OSS)";
    default:
      return "Disabled";
    }
  }

  /**
   * \brief Get Winetricks Audio driver string   *
   * \return std::string (since it's not used in GTK GUI)
   */
  inline static std::string get_winetricks_string(AudioDriver audio)
  {
    switch (audio)
    {
    case AudioDriver::pulseaudio:
      return "pulse";
    case AudioDriver::alsa:
      return "alsa";
    case AudioDriver::coreaudio:
      return "coreaudio";
    case AudioDriver::oss:
      return "oss";
    default:
      return "disabled";
    }
  }
};

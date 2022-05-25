/**
 * Copyright (c) 2019-2022 WineGUI
 *
 * \file    bottle_manager.h
 * \brief   Bottle manager controller
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

#include <gtkmm.h>
#include <list>
#include <map>
#include <mutex>
#include <string>
#include <thread>

#include "bottle_types.h"

using std::string;

// Forward declaration
class MainWindow;
class SignalDispatcher;
class BottleItem;

/**
 * \class BottleManager
 * \brief Controller that controls it all
 */
class BottleManager
{
public:
  // Signals
  sigc::signal<void> reset_acctive_bottle;   /*!< Send signal: Clear the current active bottle */
  sigc::signal<void> bottle_removed;         /*!< Send signal: When the bottle is confirmed to be removed */
  Glib::Dispatcher finished_package_install; /*!< Signal that Wine package install is completed */

  explicit BottleManager(MainWindow& main_window);
  virtual ~BottleManager();

  void prepare();
  void update_bottles();
  void new_bottle(SignalDispatcher* caller,
                  Glib::ustring name,
                  BottleTypes::Windows windows_version,
                  BottleTypes::Bit bit,
                  Glib::ustring virtual_desktop_resolution,
                  bool disable_gecko_mono,
                  BottleTypes::AudioDriver audio);
  void update_bottle(SignalDispatcher* caller,
                     Glib::ustring name,
                     BottleTypes::Windows windows_version,
                     Glib::ustring virtual_desktop_resolution,
                     BottleTypes::AudioDriver audio);
  void delete_bottle();
  void set_active_bottle(BottleItem* bottle);
  const Glib::ustring& get_error_message();

  // Signal handlers
  void run_program(string filename, bool is_msi_file);
  void open_c_drive();
  void reboot();
  void update();
  void kill_processes();
  void open_explorer();
  void open_console();
  void open_winecfg();
  void open_winetricks();
  void open_uninstaller();
  void open_task_manager();
  void open_registery_editor();
  void open_notepad();
  void open_wordpad();
  void open_iexplorer();
  void install_d3dx9(Gtk::Window& parent, const Glib::ustring& version);
  void install_dxvk(Gtk::Window& parent, const Glib::ustring& version);
  void install_visual_cpp_package(Gtk::Window& parent, const Glib::ustring& version);
  void install_dot_net(Gtk::Window& parent, const Glib::ustring& version);
  void install_core_fonts(Gtk::Window& parent);
  void install_liberation(Gtk::Window& parent);

private:
  // Synchronizes access to data members
  mutable std::mutex mutex_;

  MainWindow& main_window_;
  string bottle_location_;
  std::list<BottleItem> bottles_;
  BottleItem* active_bottle_;
  bool is_wine64_bit_;

  //// error_message is used by both the GUI thread and NewBottle thread (used a 'temp' location)
  Glib::ustring error_message_;

  bool is_bottle_not_null();
  Glib::ustring get_deinstall_mono_command();
  string get_wine_version();
  std::map<string, unsigned long> get_bottle_paths();
  std::list<BottleItem> create_wine_bottles(string wine_version, std::map<string, unsigned long> bottle_dirs);
};

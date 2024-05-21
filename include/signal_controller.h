/**
 * Copyright (c) 2019-2023 WineGUI
 *
 * \file    signal_controller.h
 * \brief   Handles different GTK signals and dispatch or connect them to other methods/handlers within WineGUI
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

#include "bottle_types.h"
#include <gtkmm.h>
#include <thread>

// Forward declaration
class MainWindow;
class BottleManager;
class Menu;
class PreferencesWindow;
class AboutDialog;
class BottleEditWindow;
class BottleCloneWindow;
class BottleConfigureWindow;
class AddAppWindow;
class RemoveAppWindow;
struct UpdateBottleStruct;
struct CloneBottleStruct;

/**
 * \class SignalController
 * \brief Dispatch and manage GTK signals across the app
 */
class SignalController : public Gtk::Window
{
  friend class MainWindow;

public:
  SignalController(BottleManager& manager,
                   Menu& menu,
                   PreferencesWindow& preferences_window,
                   AboutDialog& about_dialog,
                   BottleEditWindow& edit_window,
                   BottleCloneWindow& clone_window,
                   BottleConfigureWindow& configure_window,
                   AddAppWindow& add_app_window,
                   RemoveAppWindow& remove_app_window);
  virtual ~SignalController();
  void set_main_window(MainWindow* main_window);
  void dispatch_signals();

  // Signal handlers
  // signal_bottle_created(), signal_bottle_updated() and signal_bottle_cloned() are called from the thread bottle manager,
  // it's executed in the that thread. And can trigger the dispatcher (=thread safe), which gets executed in the GUI
  // thread.
  void signal_bottle_created();
  void signal_bottle_updated();
  void signal_bottle_cloned();
  void signal_error_message_during_create();
  void signal_error_message_during_update();
  void signal_error_message_during_clone();

protected:
private:
  void cleanup_bottle_manager_thread();

  // slots
  virtual bool on_mouse_button_pressed(GdkEventButton* event);
  virtual void on_new_bottle(Glib::ustring& name,
                             BottleTypes::Windows windows_version,
                             BottleTypes::Bit bit,
                             Glib::ustring& virtual_desktop_resolution,
                             bool& disable_geck_mono,
                             BottleTypes::AudioDriver audio);
  virtual void on_update_bottle(const UpdateBottleStruct& update_bottle_struct);
  virtual void on_clone_bottle(const CloneBottleStruct& clone_bottle_struct);
  virtual void on_new_bottle_created();
  virtual void on_bottle_updated();
  virtual void on_bottle_cloned();
  virtual void on_error_message_created();
  virtual void on_error_message_updated();
  virtual void on_error_message_cloned();

  MainWindow* main_window_;
  BottleManager& manager_;
  Menu& menu_;
  PreferencesWindow& preferences_window_;
  AboutDialog& about_dialog_;
  BottleEditWindow& edit_window_;
  BottleCloneWindow& clone_window_;
  BottleConfigureWindow& configure_window_;
  AddAppWindow& add_app_window_;
  RemoveAppWindow& remove_app_window_;

  // Dispatchers for handling signals from the thread towards a GUI thread
  Glib::Dispatcher bottle_created_dispatcher_;
  Glib::Dispatcher bottle_updated_dispatcher_;
  Glib::Dispatcher bottle_cloned_dispatcher_;
  Glib::Dispatcher error_message_created_dispatcher_;
  Glib::Dispatcher error_message_updated_dispatcher_;
  Glib::Dispatcher error_message_cloned_dispatcher_;
  // Thread for Bottle Manager (so it doesn't block the GUI thread)
  std::thread* thread_bottle_manager_;
};

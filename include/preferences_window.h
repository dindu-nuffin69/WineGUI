/**
 * Copyright (c) 2019-2023 WineGUI
 *
 * \file    preferences_window.h
 * \brief   WineGUI Application preferences window
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

/**
 * \class PreferencesWindow
 * \brief WineGUI preferences GTK Window class
 */
class PreferencesWindow : public Gtk::Window
{
public:
  // Signals
  sigc::signal<void> config_saved; /*!< config is saved signal */

  explicit PreferencesWindow(Gtk::Window& parent);
  virtual ~PreferencesWindow();

  void show();

protected:
  // Child widgets
  Gtk::Box vbox;           /*!< main vertical box */
  Gtk::Box hbox_buttons;   /*!< box for buttons */
  Gtk::Grid settings_grid; /*!< grid layout for settings */

  Gtk::Label header_preferences_label;                 /*!< header preferences label */
  Gtk::Label default_folder_label;                     /*!< default folder label */
  Gtk::Label display_default_wine_machine_label;       /*!< display default Wine machine label */
  Gtk::Label logging_label_heading;                    /*!< Logging header label */
  Gtk::Label logging_stderr_label;                     /*!< logging stderr label */
  Gtk::Entry default_folder_entry;                     /*!< default folder input field */
  Gtk::CheckButton display_default_wine_machine_check; /*!< display default Wine machine checkbox */
  Gtk::CheckButton enable_logging_stderr_check;        /*!< debug logging checkbox */
  Gtk::Button select_folder_button;                    /*!< select folder button */
  Gtk::Button save_button;                             /*!< save button */
  Gtk::Button cancel_button;                           /*!< cancel button */

private:
  // Signal handlers
  void on_select_folder();
  void on_select_dialog_response(int response_id, Gtk::FileChooserDialog* dialog);
  void on_cancel_button_clicked();
  void on_save_button_clicked();
};

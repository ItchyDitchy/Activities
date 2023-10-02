import math
import tkinter as tk


def calculate_velocity(displacement_entry, time_entry, result_label):
  displacement = float(displacement_entry.get())
  time = float(time_entry.get())
  velocity = displacement / time
  result_label.config(text=f"Result: {velocity} m/s")


def calculate_acceleration(velocity_entry, time_entry, result_label):
  velocity = float(velocity_entry.get())
  time = float(time_entry.get())
  acceleration = velocity / time
  result_label.config(text=f"Result: {acceleration} m/s^2")


def calculate_force(mass_entry, acceleration_entry, result_label):
  mass = float(mass_entry.get())
  acceleration = float(acceleration_entry.get())
  force = mass * acceleration
  result_label.config(text=f"Result: {force} N")


def physics_calculator():
  window = tk.Toplevel()
  window.title("Physics Calculator")

  tk.Label(window, text="=== Physics Calculator ===").pack()
  tk.Label(window, text="1. Velocity Calculator").pack()
  tk.Label(window, text="2. Acceleration Calculator").pack()
  tk.Label(window, text="3. Force Calculator").pack()

  choice_label = tk.Label(window, text="Enter your choice:")
  choice_label.pack()
  choice_entry = tk.Entry(window)
  choice_entry.pack()

  displacement_label = tk.Label(window, text="Enter displacement:")
  displacement_label.pack()
  displacement_entry = tk.Entry(window)
  displacement_entry.pack()

  time_label = tk.Label(window, text="Enter time:")
  time_label.pack()
  time_entry = tk.Entry(window)
  time_entry.pack()

  velocity_label = tk.Label(window, text="Enter velocity:")
  velocity_label.pack()
  velocity_entry = tk.Entry(window)
  velocity_entry.pack()

  acceleration_label = tk.Label(window, text="Enter acceleration:")
  acceleration_label.pack()
  acceleration_entry = tk.Entry(window)
  acceleration_entry.pack()

  mass_label = tk.Label(window, text="Enter mass:")
  mass_label.pack()
  mass_entry = tk.Entry(window)
  mass_entry.pack()

  calculate_button = tk.Button(
    window,
    text="Calculate",
    command=lambda: calculate_velocity(displacement_entry, time_entry,
                                       result_label)
    if choice_entry.get() == "1" else calculate_acceleration(
      velocity_entry, time_entry, result_label)
    if choice_entry.get() == "2" else calculate_force(
      mass_entry, acceleration_entry, result_label))
  calculate_button.pack()

  result_label = tk.Label(window, text="Result: ")
  result_label.pack()


def calculate_moles_to_grams(moles_entry, molar_mass_entry, result_label):
  moles = float(moles_entry.get())
  molar_mass = float(molar_mass_entry.get())
  grams = moles * molar_mass
  result_label.config(text=f"Result: {grams} g")


def calculate_grams_to_moles(grams_entry, molar_mass_entry, result_label):
  grams = float(grams_entry.get())
  molar_mass = float(molar_mass_entry.get())
  moles = grams / molar_mass
  result_label.config(text=f"Result: {moles} mol")


def chemistry_calculator():
  window = tk.Toplevel()
  window.title("Chemistry Calculator")

  tk.Label(window, text="=== Chemistry Calculator ===").pack()
  tk.Label(window, text="1. Moles to Grams").pack()
  tk.Label(window, text="2. Grams to Moles").pack()
  choice_label = tk.Label(window, text="Enter your choice:")
  choice_label.pack()
  choice_entry = tk.Entry(window)
  choice_entry.pack()

  moles_label = tk.Label(window, text="Enter moles:")
  moles_label.pack()
  moles_entry = tk.Entry(window)
  moles_entry.pack()

  molar_mass_label = tk.Label(window, text="Enter molar mass:")
  molar_mass_label.pack()
  molar_mass_entry = tk.Entry(window)
  molar_mass_entry.pack()

  grams_label = tk.Label(window, text="Enter grams:")
  grams_label.pack()
  grams_entry = tk.Entry(window)
  grams_entry.pack()

  calculate_button = tk.Button(
    window,
    text="Calculate",
    command=lambda: calculate_moles_to_grams(moles_entry, molar_mass_entry,
                                             result_label)
    if choice_entry.get() == "1" else calculate_grams_to_moles(
      grams_entry, molar_mass_entry, result_label)
    if choice_entry.get() == "2" else None)
  calculate_button.pack()

  result_label = tk.Label(window, text="Result: ")
  result_label.pack()


def calculate_distance(x1_entry, y1_entry, x2_entry, y2_entry, result_label):
  x1 = float(x1_entry.get())
  y1 = float(y1_entry.get())
  x2 = float(x2_entry.get())
  y2 = float(y2_entry.get())
  distance = math.sqrt((x2 - x1)**2 + (y2 - y1)**2)
  result_label.config(text=f"Result: {distance}")


def distance_calculator():
  window = tk.Toplevel()
  window.title("Distance Calculator")

  tk.Label(window, text="=== Distance Calculator ===").pack()

  x1_label = tk.Label(window, text="Enter the x coordinate of point 1:")
  x1_label.pack()
  x1_entry = tk.Entry(window)
  x1_entry.pack()

  y1_label = tk.Label(window, text="Enter the y coordinate of point 1:")
  y1_label.pack()
  y1_entry = tk.Entry(window)
  y1_entry.pack()

  x2_label = tk.Label(window, text="Enter the x coordinate of point 2:")
  x2_label.pack()
  x2_entry = tk.Entry(window)
  x2_entry.pack()

  y2_label = tk.Label(window, text="Enter the y coordinate of point 2:")
  y2_label.pack()
  y2_entry = tk.Entry(window)
  y2_entry.pack()

  calculate_button = tk.Button(
    window,
    text="Calculate",
    command=lambda: calculate_distance(x1_entry, y1_entry, x2_entry, y2_entry,
                                       result_label))
  calculate_button.pack()

  result_label = tk.Label(window, text="Result: ")
  result_label.pack()


def main():

  def open_physics_calculator():
    main_window.withdraw()
    physics_calculator()

  def open_chemistry_calculator():
    main_window.withdraw()
    chemistry_calculator()

  def open_distance_calculator():
    main_window.withdraw()
    distance_calculator()

  main_window = tk.Tk()
  main_window.title("Python App")

  tk.Label(main_window, text="=== Python App ===").pack()
  tk.Label(main_window, text="1. Physics Calculator").pack()
  tk.Label(main_window, text="2. Chemistry Calculator").pack()
  tk.Label(main_window, text="3. Distance Calculator").pack()
  tk.Label(main_window, text="4. Quit").pack()

  choice_label = tk.Label(main_window, text="Enter your choice:")
  choice_label.pack()
  choice_entry = tk.Entry(main_window)
  choice_entry.pack()

  physics_button = tk.Button(main_window,
                             text="Open Physics Calculator",
                             command=open_physics_calculator)
  physics_button.pack()

  chemistry_button = tk.Button(main_window,
                               text="Open Chemistry Calculator",
                               command=open_chemistry_calculator)
  chemistry_button.pack()

  distance_button = tk.Button(main_window,
                              text="Open Distance Calculator",
                              command=open_distance_calculator)
  distance_button.pack()

  quit_button = tk.Button(main_window, text="Quit", command=main_window.quit)
  quit_button.pack()

  main_window.mainloop()


if __name__ == "__main__":
  main()
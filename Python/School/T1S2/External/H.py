# mimimum wind speeds in km/h for PAG-ASA's Tropical Cyclone Intensity Scale
tropical_depression = 33
tropical_storm = 62
severe_tropical_storm = 89
typhoon = 118
supertyphoon = 221

wind_speed = int(input("Wind Speed: "))
if tropical_storm <= wind_speed < severe_tropical_storm:
    print("Yes")
else:
    print("False")
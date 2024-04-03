def online_count(statuses):
  if type(online_count) == dict:
    return -1
  count = 0
  for index in statuses.items():
    if type(index) != tuple:
      return -1
    if (index[1] == "online"):
      count += 1
  return count
    
statuses = {
    "Alice": "online",
    "Bob": "offline",
    "Eve": "online",
}

print (online_count(statuses))

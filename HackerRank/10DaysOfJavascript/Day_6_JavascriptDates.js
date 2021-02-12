function getDayName(dateString) {
  let weeks = [
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
  ];

  let day = new Date(dateString).getDay();

  return weeks[day];
}

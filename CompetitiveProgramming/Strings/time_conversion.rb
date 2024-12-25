#!/usr/bin/env ruby

def time_conversion(s)
  ampm = s[-2..]
  hour = s[...2].to_i # We are guaranteed that the hour is zero-padded.
  minute = s[3..4]
  second = s[6..7]

  # If the 12-hour time is AM, then it is the same for 24-hour, except for 12,
  # which becomes the 0th hour of the day.
  #
  # If the 12-hour time is PM, then we add the 12 morning hours to that number,
  # except if it's 12, which remains the same on both.

  case
  when ampm.casecmp?("am")
    if hour == 12 then hour = 0 end
  when ampm.casecmp?("pm")
    if hour < 12 then hour += 12  end
  end

  "#{"%02d" % hour}:#{minute}:#{second}"
end

# Available Test Cases:
#
# Input: 07:05:45PM
# Output: 19:05:45
#
# Input:
# Output:

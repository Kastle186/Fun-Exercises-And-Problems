#!/usr/bin/env ruby

def balanced_brackets(str)
  stack = []
  opening_brackets = ['(', '[', '{']

  # If it's an opening bracket, then we just push it onto the stack. Now, if it
  # is a balanced closing bracket, it must match its opening counterpart at the
  # top of the stack. Otherwise, the string is not balanced and we can finish early.

  str.chars.each do |c|
    if opening_brackets.include?(c)
      stack.push(c)
    else
      case c
      when ')'
        unless stack.pop == '(' then return "NO" end
      when ']'
        unless stack.pop == '[' then return "NO" end
      when '}'
        unless stack.pop == '{' then return "NO" end
      end
    end
  end

  # We might not have found any mismatching bracket, but we still have to check
  # whether there were any remaining unclosed ones. Hence, we only confirm "YES"
  # if our stack is empty. Otherwise, then "NO".
  if stack.empty? then "YES" else "NO" end
end

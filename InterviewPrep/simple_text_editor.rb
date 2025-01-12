#!/usr/bin/env ruby

class EditorText
  attr_accessor :text

  private

  attr_accessor :op_stack

  public

  def initialize
    @text = ""
    @op_stack = []
  end

  # We append the string to the editor text. Then, if we didn't arrive here by
  # means of an undo, we add to the operations stack a tuple containing a 1 and
  # the length of the string. This will tell the undo() function later on, that
  # it has to delete that amount of characters from the editor text.

  def append(str, is_undo = false)
    @text << str
    @op_stack << [1, str.length] unless is_undo
  end

  # We delete 'k' amount of characters from the editor text. Then, if we didn't
  # arrive here by means of an undo, we add to the operations stack a tuple containing
  # a 2, and the substring that was deleted. This will thell the undo() function#
  # that it has to append that substring back to the editor text.

  def delete(k, is_undo = false)
    to_del = @text[-k..]
    @text = @text[...-k]
    @op_stack << [2, to_del] unless is_undo
  end

  # We print the kth character of the editor text.

  def print(k, fptr)
    fptr.write("#{@text[k]}\n")
  end

  # We pop the last operation from the stack. Then, we call delete() or append(),
  # depending on which operation we are undoing.

  def undo
    last_op = @op_stack.pop

    if last_op[0] == 1
      delete(last_op[1], true)
    else
      append(last_op[1], true)
    end
  end
end

# NOTE: The problem's description specified that it was guaranteed we would not
#       get invalid inputs.

fptr = File.open(ENV['OUTPUT_PATH'], 'w')
q = gets.strip.to_i
the_editor = EditorText.new

operations = {}
operations["1"] = -> (str_arg) { the_editor.append(str_arg) }
operations["2"] = -> (k_arg) { the_editor.delete(k_arg.to_i) }
operations["3"] = -> (k_arg, fptr_arg) { the_editor.print(k_arg.to_i - 1, fptr_arg) }
operations["4"] = -> { the_editor.undo }

q.times do
  query = gets.strip.split
  op_code = query[0]

  case op_code
  when "3" then operations[op_code].(query[1], fptr)
  when "4" then operations[op_code].()
  else operations[op_code].(query[1])
  end
end

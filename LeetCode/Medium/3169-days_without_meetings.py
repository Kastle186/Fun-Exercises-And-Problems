#!/usr/bin/env python3

# Name: 3169. Count Days Without Meetings
# Topics: Array, Sorting


def count_days(days: int, meetings: list[list[int]]) -> int:
    # First, sort the meetings by start time.
    meetings.sort(key=lambda x: x[0])

    # Then, we have to consider the possibility of there being free time before
    # all of the meetings begin. We are guaranteed by the problem that all inputs
    # will be valid (i.e. greater or equal to 1).

    work_days = (meetings[0][0] - 1)
    latest_end = meetings[0][1]

    # Next, we'll go through the list of meetings to find the free time. As there
    # can be overlapping meetings, we will assume the employee sorts it out on their
    # own, but regardless of that, it is considered meeting time.

    for i in range(len(meetings) - 1):
        next_meeting = meetings[i+1]

        # If the next meeting begins after the employee's time, then we can stop here.
        if next_meeting[0] > days:
            break

        # Next, if the next meeting starts after the current latest end time, then
        # we've got some free time on our hands.
        if next_meeting[0] > latest_end:
            work_days += (next_meeting[0] - latest_end - 1)

        # Update the latest end if needed.
        latest_end = max(latest_end, next_meeting[1])

    # There can also be free days after all the meetings have passed.
    if latest_end < days:
        work_days += (days - latest_end)

    return work_days


def main():
    no_meetings_1 = count_days(10, [[5, 7], [1, 3], [9, 10]])
    no_meetings_2 = count_days(5, [[2, 4], [1, 3]])
    no_meetings_3 = count_days(6, [[1, 6]])
    no_meetings_4 = count_days(57, [[3,49],[23,44],[21,56],[26,55],[23,52],[2,9],[1,48],[3,31]])
    no_meetings_5 = count_days(8, [[2, 3], [3, 5], [8, 8]])

    print(no_meetings_1)
    print(no_meetings_2)
    print(no_meetings_3)
    print(no_meetings_4)
    print(no_meetings_5)


if __name__ == '__main__':
    main()

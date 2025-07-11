def solution(diffs, times, limit):
    answer = 0

    left, right = 1, 100000
    while left <= right:
        mid = (left + right) // 2

        solving_time = 0
        for i in range(len(diffs)):
            solving_time += times[i] + (times[i - 1] + times[i]) * max(0, (diffs[i] - mid))

        if solving_time <= limit:
            right = mid - 1
        else:
            left = mid + 1

    answer = left
    return answer
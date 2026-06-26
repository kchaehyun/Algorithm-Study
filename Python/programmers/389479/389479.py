def solution(players, m, k):
    answer = 0
    time = [0] *(24+k+1)
    now_server = 0
    need = 0
    for i in range(24) :
        if time[i] != 0 :
            now_server -= time[i]
        if players[i] >= m*(now_server+1) :
            need = players[i]//m - now_server
            answer += need
            now_server += need
            time[i+k] += need
    return answer

print(solution([0, 2, 3, 3, 1, 2, 0, 0, 0, 0, 4, 2, 0, 6, 0, 4, 2, 13, 3, 5, 10, 0, 1, 5],3,5))
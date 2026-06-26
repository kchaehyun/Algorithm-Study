from itertools import product

def solution(users, emoticons):
    answer = []
    ratios = [10, 20, 30, 40]
    discounts = list(product(ratios, repeat=len(emoticons)))
    for dis in discounts :
        register, money = 0, 0
        for u in users:
            user_money = 0
            for i,dis_i in enumerate(dis) :
                if dis_i >= u[0] :
                    user_money += emoticons[i]*((100-dis_i)/100)
            if user_money >= u[1] :
                register += 1
            else :
                money += user_money
        answer.append((register,money))
    answer.sort(key = lambda x : (-x[0],-x[1]))
        
    return answer[0]
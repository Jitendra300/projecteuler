def neat_trick():
    prev_num = 1
    prev_den = 1000000
    cur_num,cur_den = None,None
    next_num = 999999
    next_den =  1000000

    while(True):
        cur_num = prev_num+next_num
        cur_den = prev_den+next_den

        cur_num, cur_den = reduce_to_low_terms(cur_num, cur_den)
        whole_fraction = cur_num/cur_den
        
        if(cur_den > 1000000):
            print(prev_num, "/", prev_den)
            break
        if(whole_fraction < (3/7)):
            prev_num = cur_num
            prev_den = cur_den
        else:
            next_num = cur_num
            next_den = cur_den

        
            

neat_trick()

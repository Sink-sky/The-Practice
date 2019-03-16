import operator
from functools import cmp_to_key

users_info = [['1','1','1','1']
              ,['2','1','1','1']
              ,['3','1','1','1']]
# 数据集中的用户数据
# 格式为 用户ID,性别,年龄,职业
# movie_info = []
# 数据集中的电影数据
# 格式为 电影ID,电影名称
# 其中分类也是一个列表
ratings_info = [['1','1','4'],
                ['2','1','5'],
                ['3','2','2'],
                ['1','2','5'],
                ['1', '3', '1'],
                ['2', '3', '1'],
                ['3', '3', '1']
                ]
# 数据集中的打分数据
# 格式为 用户ID,电影ID,分级(int)

new_user_info = ['4','1','1','1']
# 新用户的用户数据,格式同数据集中的用户数据
new_ratings_info = [['4','3','1']]
# 新用户的打分数据,格式同数据集中的打分数据

same_user_ratings_info = []
# 筛选用户的评分信息

same_user_movie = []
# 筛选用户所看过的电影id

recommend_ls = []
# 推荐列表


def filter_info():
    """
    从数据集中选出计算需要用到的数据
    即筛选用户信息一致的数据库用户信息做计算
    :return:无
    """
    for user in users_info:
        if operator.eq(user[1:4], new_user_info[1:4]):
            ratings_list = []
            for rating in ratings_info:
                if rating[0] == user[0]:
                    ratings_list.append(rating)
                    if rating[1] not in same_user_movie:
                        same_user_movie.append(rating[1])
            same_user_ratings_info.append(ratings_list)


def laplace_smoothing(numerator, denominator, a=1):
    """
    拉普拉斯平滑化
    :param numerator:计算概率的分子
    :param denominator:计算概率的分母
    :param a:拉普拉斯平滑参数
    :return:拉普拉斯平滑化之后的概率
    """
    return (numerator + a) / (denominator + 2 * a)


def score_comp(a, b):
    """
    推荐列表排序函数
    :param a:比较变量a
    :param b:比较变量b
    :return:a是否大于b
    """
    return b[1] - a[1]


# 我们将用户打分4分及以上视为打高分,其余视为低分
def NBCF():
    """
    朴素贝叶斯协同过滤

    :return:无
    """
    high_score = 0
    low_score = 0
    for user_rating in new_ratings_info:
        if user_rating[2] >= '4':
            high_score += 1
        else:
            low_score += 1
    high_score_PR = laplace_smoothing(high_score, high_score+low_score)
    low_score_PR = 1 - high_score_PR
    for movie_id in same_user_movie:
        high_score_rating_PR = high_score_PR
        low_score_rating_PR = low_score_PR
        if movie_id in [item[1] for item in new_ratings_info]:
            continue
        for new_rating_movie in new_ratings_info:
            same_rating_time = 0
            high_score_time = 0
            low_score_time = 0
            for rating in same_user_ratings_info:
                rating_movie_id = [item[1] for item in rating]
                rating_score = [item[2] for item in rating]
                if movie_id in rating_movie_id and new_rating_movie[1] in rating_movie_id:
                    flag1 = 0
                    flag2 = 0
                    if rating_score[rating_movie_id.index(new_rating_movie[1])] >= '4':
                        flag1 = 1
                    if new_rating_movie[2] >= '4':
                        flag2 = 1
                    if flag1 + flag2 == 0 or flag1 + flag2 == 2:
                        same_rating_time += 1
                    if rating_score[rating_movie_id.index(movie_id)] >= '4':
                        high_score_time += 1
                    else:
                        low_score_time += 1
            high_score_rating_PR *= laplace_smoothing(high_score_time, same_rating_time)
            low_score_rating_PR *= laplace_smoothing(low_score_time, same_rating_time)
        recommend_ls.append([movie_id, high_score_rating_PR - low_score_rating_PR])
        recommend_ls.sort(key=cmp_to_key(score_comp))


if __name__ == "__main__":
    filter_info()
    NBCF()
    for ans in recommend_ls:
        print(ans[0], end=' ')
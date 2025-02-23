# 介绍
  这是一个从 _2025/2/21_ 开始然后**3**天速通随便乱写的酒店管理系统项目。  
  __当然，这也是一个随便乱写的markdown__

# 功能  
    登录  
    注册  
    管理员 
        查顾客信息（所有人/某个人）  
        删除顾客  
        查房  
        管理房间是否可用  
    顾客
        充值  
        订房  
        退房  
        查余额  
        查房  
        查信息（自己）  

# 技术栈  
本 __蒟蒻__ 使用c++语言开发该项目,用到了以下语法和特性：  
    1. 使用txt储存管理员、顾客、房间信息（问：为什么不用mysql？ 答：因为不会）  
    2. 运行时使用map来暂时储存信息，为了防止意外退出时未保存信息，每运行一步就进行一次存储（既浪费时间又浪费内存）（问：所以为什么不学mysql？ 答：因为没时间qwq）  
        对于各文件的转换成map的内容  
        顾客map    键：用户名 值：密码    余额    房间    房间类型  
        管理者map    键：用户名 值：密码  
        房间map    键：房号 值：普通/豪华    单人/双人    价格    是否已预订  

# 提示  
没有_zh的是英文，有_zh的是中文(我怕中文显示会乱码)

最后一次更新：2025/2/23 5pm (好饿啊，吃个饭先)

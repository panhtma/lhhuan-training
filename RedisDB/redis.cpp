#include <iostream>
#include <hiredis/hiredis.h>

int main() {
    // 1. Kết nối đến Redis Server (Đang chạy trên localhost qua Docker)
    redisContext *c = redisConnect("10.46.4.53", 6379);
    
    if (c == NULL || c->err) {
        if (c) {
            std::cerr << "Loi ket noi: " << c->errstr << std::endl;
            redisFree(c);
        } else {
            std::cerr << "Khong the phan bo context Redis" << std::endl;
        }
        return 1;
    }
    std::cout << "Ket noi Redis thanh cong!" << std::endl;

    // 2. Thực thi lệnh HSET
    // Hàm redisCommand trả về một con trỏ redisReply. BẠN PHẢI FREE NÓ ĐỂ TRÁNH MEMORY LEAK!
    redisReply *reply = (redisReply *)redisCommand(c, "HSET cpp:user:1 name %s age %d", "Gemini", 1);
    std::cout << "HSET status (So field duoc tao): " << reply->integer << std::endl;
    freeReplyObject(reply); // Quan trọng

    // 3. Thực thi lệnh HGET
    reply = (redisReply *)redisCommand(c, "HGET cpp:user:1 name");
    if (reply->type == REDIS_REPLY_STRING) {
        std::cout << "HGET name: " << reply->str << std::endl;
    }
    freeReplyObject(reply); // Quan trọng

    // 4. Ngắt kết nối
    redisFree(c);
    
    return 0;
}
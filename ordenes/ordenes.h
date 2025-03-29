#ifndef ORDER_H
#define ORDER_H
//definimos que  caracteristica (atributos) tiene una orden
typedef struct {
    int pizza_id;
    int order_id;
    char pizza_name_id[64];
    int quantity;
    char order_date[16];
    char order_time[16];
    float unit_price;
    float total_price;
    char pizza_size[8];
    char pizza_category[32];
    char pizza_ingredients[256];
    char pizza_name[64];
} order;
#endif
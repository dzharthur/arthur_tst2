#ifndef _APP_AT_H
#define _APP_AT_H

#include <stdint.h>
#include "co_list.h"
#include <stdbool.h>

struct uart_msg_elem_t {
    struct co_list_hdr hdr;
    uint8_t *data;
    uint16_t data_len;
};

struct uart_lp_env_t{
    co_list_t msg_list;
    bool tx_sending;
    bool rx_pending;
    int8_t pending_num;
    uint8_t rx_state;
    uint16_t rx_size;
};


extern struct uart_lp_env_t uart_lp_env;

void app_at_cmd_recv_handler(uint8_t *data, uint16_t length);

void app_at_init_app(void);

void uart_slave_send_wake_ind(void);

void uart_slave_init(void);

void uart_send(uint8_t *data, uint16_t data_len);

void uart_send_ack(void);

void uart_req_tx(void);

#endif //_APP_AT_H


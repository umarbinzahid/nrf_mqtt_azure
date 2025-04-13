/*
 * Copyright (c) 2025 MAXLUCIS
 *
 * SPDX-License-Identifier: Apache-2.0
 */

 #ifndef __MQTT_H__
 #define __MQTT_H__
 
int add_credentials(void);
void connect_to_cloud_and_publish(void);
void abort_mqtt_connection(void);
 
 #endif /* __MQTT_H__ */
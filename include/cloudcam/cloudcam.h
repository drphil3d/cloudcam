#ifndef CLOUDCAM_H
#define CLOUDCAM_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <curl/curl.h>
#include "aws_iot_mqtt_client_interface.h"

// represents a cloudcam client context
typedef struct {
    char *app_dir_path;
    AWS_IoT_Client *iotc;
} cloudcam_ctx;

// public functions
int cloudcam_init_ctx(cloudcam_ctx *ctx, char *app_dir_path);
int cloudcam_free_ctx(cloudcam_ctx *ctx);
IoT_Error_t cloudcam_connect_blocking(cloudcam_ctx *ctx);

#endif  // CLOUDCAM_H
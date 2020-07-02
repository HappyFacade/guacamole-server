/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include "config.h"

#include "argv.h"
#include "auth.h"
#include "vnc.h"

#include <guacamole/argv.h>
#include <guacamole/client.h>
#include <rfb/rfbclient.h>
#include <rfb/rfbproto.h>

#include <string.h>

char* guac_vnc_get_password(rfbClient* client) {

    guac_client* gc = rfbClientGetClientData(client, GUAC_VNC_CLIENT_KEY);
    guac_vnc_client* vnc_client = (guac_vnc_client*) gc->data;
    guac_vnc_settings* settings = vnc_client->settings;

    int num_required = 0;
    const char* required_params[4];

    /* Build list of required credentials based on which settings were provided */
    if (settings->password == NULL || strcmp(settings->password, "") == 0)
        required_params[num_required++] = GUAC_VNC_ARGV_PASSWORD;

    /* Terminate list of required credentials */
    required_params[num_required] = NULL;

    /* Request any required credentials */
    if (num_required > 0) {
        guac_client_log(gc, GUAC_LOG_INFO, "Prompting for required credentials.");
        guac_client_owner_send_required(gc, required_params);
        guac_argv_await(required_params);
    }

    return settings->password;

}


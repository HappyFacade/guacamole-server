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
#include "rdp.h"
#include "settings.h"

#include <guacamole/client.h>
#include <guacamole/user.h>

#include <stdlib.h>
#include <string.h>

int guac_rdp_receive_credentials(guac_user* user, const char* mimetype,
        const char* name, const char* value, void* data) {

    guac_client* client = user->client;
    guac_rdp_client* rdp_client = (guac_rdp_client*) client->data;
    guac_rdp_settings* settings = rdp_client->settings;

    /* Represent empty values as NULL */
    if (strcmp(value, "") == 0)
        value = NULL;

    /* Update domain */
    if (strcmp(name, GUAC_RDP_ARGV_DOMAIN) == 0) {

        free(settings->domain);
        settings->domain = guac_rdp_strdup(value);

        free(*rdp_client->prompt_domain);
        *rdp_client->prompt_domain = guac_rdp_strdup(value);

    }

    /* Update username */
    else if (strcmp(name, GUAC_RDP_ARGV_USERNAME) == 0) {

        free(settings->username);
        settings->username= guac_rdp_strdup(value);

        free(*rdp_client->prompt_username);
        *rdp_client->prompt_username = guac_rdp_strdup(value);

    }

    /* Update password */
    else if (strcmp(name, GUAC_RDP_ARGV_PASSWORD) == 0) {

        free(settings->password);
        settings->password = guac_rdp_strdup(value);

        free(*rdp_client->prompt_password);
        *rdp_client->prompt_password = guac_rdp_strdup(value);

    }

    return 0;

}


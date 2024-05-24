#!/usr/bin/env python
#  -*- coding: utf-8 -*-
#  Copyright Huawei Technologies Co., Ltd. 2024-2024. All rights reserved

import subprocess

result = subprocess.run(['echo', 'hello, world!'], capture_output=True, text=True)
print(result.stdout)
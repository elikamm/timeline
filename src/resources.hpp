#pragma once

struct resource {
    const unsigned char *data;
    unsigned size;
};

namespace resources {
    extern const resource test;
}
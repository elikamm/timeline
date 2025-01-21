#pragma once

struct Resource {
    const unsigned char *data;
    unsigned size;
};

namespace Resources {
    extern const Resource Test;
}
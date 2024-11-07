# ofxBooLINQ

[boolinq](https://github.com/k06a/boolinq) for openFrameworks (tested on v0.12.0, boolinq version: 3.0.4)

## Usage

See [example](example). (Please use `projectGenerator` before run it)

```cpp
#include "boolinq/boolinq.h"

struct Man {
    std::string name;
    int age;
};

using namespace boolinq;

void ofApp::setup(){
    ofLogToConsole();

    int src[] = {1,2,3,4,5,6,7,8};
    auto dst = from(src).where( [](int a) { return a % 2 == 1; })      // 1,3,5,7
                    .select([](int a) { return a * 2; })           // 2,6,10,14
                    .where( [](int a) { return a > 2 && a < 12; }) // 6,10
                    .toStdVector();

    ofLogNotice("ofApp") << "dst: " << ofToString(dst);
    
    Man src2[] = {
        {"Kevin",14},
        {"Anton",18},
        {"Agata",17},
        {"Terra",20},
        {"Layer",15},
    };

    auto dst2 = from(src2).where([](const Man & man) { return man.age < 18; })
                        .orderBy([](const Man & man) { return man.age; })
                        .select( [](const Man & man) { return man.name; })
                        .toStdVector();

    ofLogNotice("ofApp") << "dst2: " << ofToString(dst2);
}

// Result:
// [notice ] ofApp: dst: {6, 10}
// [notice ] ofApp: dst2: {Kevin, Layer, Agata}
```

## LICENSE

- boolinq: [MIT License](https://github.com/k06a/boolinq/blob/3.0.4/LICENSE)

NOTE: No specific copyright is claimed for this repository changes (for oF binding), but the [Apache License 2.0](LICENSE_APACHE) or [MIT License](LICENSE_MIT) can be applied if necessary.

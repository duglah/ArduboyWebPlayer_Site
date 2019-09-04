function makeAlert(text) {
    //alert(text);
    console.log(text)
}

// Other way around from: https://github.com/TEAMarg/arduboy-image-converter
function transformImageData(buffer, width, height) {
    var pageCount = Math.ceil(height/ 8)
    var columnCount = width
    var currentByte = 0
    var databuffer = []

    // Read the sprite page-by-page
    for(var page = 0; page < pageCount; page++) {

        // Read the page column-by-column
        for(var column = 0; column < columnCount; column++) {

            // Read the column into a byte
            var spriteByte = buffer[currentByte];
            for(var yPixel = 0; yPixel < 8; yPixel++) {
                var x = column
                var y = page * 8 + yPixel
                var pos = x * 4 + width * y * 4
                
                var color = spriteByte & (1 << yPixel)

                if(color > 0) {
                    databuffer[pos + 0] = 255
                    databuffer[pos + 1] = 255
                    databuffer[pos + 2] = 255
                    databuffer[pos + 3] = 255
                }
                else {
                    databuffer[pos + 0] = 0
                    databuffer[pos + 1] = 0
                    databuffer[pos + 2] = 0
                    databuffer[pos + 3] = 255
                }
            }
            currentByte++;
        }
    }

    return databuffer
}

var imgData = []

if (typeof mergeInto !== 'undefined') mergeInto(LibraryManager.library, {
    jsBegin: function() {
        console.log("jsBegin")
    },
    jsSetFrameRate: function(rate) {
        console.log("setFramerate to " + rate)
    },
    jsNextFrame: function() {
        console.log("jsNextFrame")
        return true
    },
    jsSetCursor: function(x,y) {
        console.log("jsSetCursor " + x + " " + y)
    },
    jsDisplay: function (pointer) {
        console.log("jsDisplay")
        const data = new Uint8ClampedArray(Module.HEAP8.buffer, pointer, width * height / 8)
        imgData = new Uint8ClampedArray(transformImageData(data, width, height))
    },
    jsPrint: function(text) {
        text = UTF8ToString(text, 20);
        console.log("jsPrint: " + text);
    },
    jsClear: function() {
        console.log("jsClear")
    }
});
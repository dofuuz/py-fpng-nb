#include <nanobind/nanobind.h>
#include <nanobind/ndarray.h>
// #include <nanobind/stl/vector.h>

#include <fpng.h>


namespace nb = nanobind;
using namespace nb::literals;
using nb::ndarray;

using namespace fpng;


nb::bytes cfpng_encode_ndarray(
        ndarray<const uint8_t, nb::ndim<3>, nb::c_contig, nb::device::cpu> img) {
    const uint32_t w = img.shape(0);
    const uint32_t h = img.shape(1);
    const uint32_t num_chans = img.shape(2);
	// bool fpng_encode_image_to_memory(const void* pImage, uint32_t w, uint32_t h, uint32_t num_chans, std::vector<uint8_t>& out_buf, uint32_t flags = 0);

    std::vector<uint8_t> out_buf;
    auto ret = fpng_encode_image_to_memory(img.data(), w, h, num_chans, out_buf);

    if (!ret) std::runtime_error("fpng_encode_image_to_memory() failed!");

    // TODO: return by ref (not copy)
    return nb::bytes(out_buf.data(), out_buf.size());
}


NB_MODULE(fpng_ext, m) {
    m.doc() = "This is a \"hello world\" example with nanobind";
    m.def("add", [](int a, int b) { return a + b; }, "a"_a, "b"_a);

    m.def("init", &fpng_init);
    m.def("cpu_supports_sse41", &fpng_cpu_supports_sse41);
    // m.def("crc32", );
    // m.def("adler32", );

    // m.attr("FPNG_ENCODE_SLOWER", FPNG_ENCODE_SLOWER);
    // m.attr("FPNG_FORCE_UNCOMPRESSED", FPNG_FORCE_UNCOMPRESSED);

    // m.def("encode_image_to_memory", );
    // m.def("encode_image_to_file", );

    m.def("encode_ndarray", &cfpng_encode_ndarray);

    // m.attr("FPNG_DECODE_SUCCESS") = FPNG_DECODE_SUCCESS;
    // m.attr("FPNG_DECODE_NOT_FPNG") = FPNG_DECODE_NOT_FPNG;
    // m.attr("FPNG_DECODE_INVALID_ARG") = FPNG_DECODE_INVALID_ARG;
    // m.attr("FPNG_DECODE_FAILED_NOT_PNG") = FPNG_DECODE_FAILED_NOT_PNG;
    // m.attr("FPNG_DECODE_FAILED_HEADER_CRC32") = FPNG_DECODE_FAILED_HEADER_CRC32;
    // m.attr("FPNG_DECODE_FAILED_INVALID_DIMENSIONS") = FPNG_DECODE_FAILED_INVALID_DIMENSIONS;
    // m.attr("FPNG_DECODE_FAILED_DIMENSIONS_TOO_LARGE") = FPNG_DECODE_FAILED_DIMENSIONS_TOO_LARGE;
    // m.attr("FPNG_DECODE_FAILED_CHUNK_PARSING") = FPNG_DECODE_FAILED_CHUNK_PARSING;
    // m.attr("FPNG_DECODE_FAILED_INVALID_IDAT") = FPNG_DECODE_FAILED_INVALID_IDAT;
    // m.attr("FPNG_DECODE_FILE_OPEN_FAILED") = FPNG_DECODE_FILE_OPEN_FAILED;
    // m.attr("FPNG_DECODE_FILE_TOO_LARGE") = FPNG_DECODE_FILE_TOO_LARGE;
    // m.attr("FPNG_DECODE_FILE_READ_FAILED") = FPNG_DECODE_FILE_READ_FAILED;
    // m.attr("FPNG_DECODE_FILE_SEEK_FAILED") = FPNG_DECODE_FILE_SEEK_FAILED;

    m.def("get_info", &fpng_get_info);
    m.def("decode_memory", &fpng_decode_memory);
    // m.def("decode_file", &fpng_decode_file);
}

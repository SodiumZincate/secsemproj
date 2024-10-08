// This file was generated by qtwaylandscanner
// source file is /build/qt6-wayland/src/qtwayland/src/client/../3rdparty/protocol/cursor-shape-v1.xml

#ifndef QT_WAYLAND_CURSOR_SHAPE_V1
#define QT_WAYLAND_CURSOR_SHAPE_V1

#include <QtWaylandClient/private/wayland-cursor-shape-v1-client-protocol.h>
#include <QByteArray>
#include <QString>

struct wl_registry;

QT_BEGIN_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_GCC("-Wmissing-field-initializers")
QT_WARNING_DISABLE_CLANG("-Wmissing-field-initializers")
#if !defined(Q_WAYLAND_CLIENT_CURSOR_SHAPE_V1_EXPORT)
#  if defined(QT_SHARED) && !defined(QT_STATIC)
#    if defined(QT_BUILD_WAYLANDCLIENT_LIB)
#      define Q_WAYLAND_CLIENT_CURSOR_SHAPE_V1_EXPORT Q_DECL_EXPORT
#    else
#      define Q_WAYLAND_CLIENT_CURSOR_SHAPE_V1_EXPORT Q_DECL_IMPORT
#    endif
#  else
#    define Q_WAYLAND_CLIENT_CURSOR_SHAPE_V1_EXPORT
#  endif
#endif

namespace QtWayland {
    class Q_WAYLAND_CLIENT_CURSOR_SHAPE_V1_EXPORT wp_cursor_shape_manager_v1
    {
    public:
        wp_cursor_shape_manager_v1(struct ::wl_registry *registry, uint32_t id, int version);
        wp_cursor_shape_manager_v1(struct ::wp_cursor_shape_manager_v1 *object);
        wp_cursor_shape_manager_v1();

        virtual ~wp_cursor_shape_manager_v1();

        void init(struct ::wl_registry *registry, uint32_t id, int version);
        void init(struct ::wp_cursor_shape_manager_v1 *object);

        struct ::wp_cursor_shape_manager_v1 *object() { return m_wp_cursor_shape_manager_v1; }
        const struct ::wp_cursor_shape_manager_v1 *object() const { return m_wp_cursor_shape_manager_v1; }
        static wp_cursor_shape_manager_v1 *fromObject(struct ::wp_cursor_shape_manager_v1 *object);

        bool isInitialized() const;

        uint32_t version() const;
        static const struct ::wl_interface *interface();

        void destroy();
        struct ::wp_cursor_shape_device_v1 *get_pointer(struct ::wl_pointer *pointer);
        struct ::wp_cursor_shape_device_v1 *get_tablet_tool_v2(struct ::zwp_tablet_tool_v2 *tablet_tool);

    private:
        struct ::wp_cursor_shape_manager_v1 *m_wp_cursor_shape_manager_v1;
    };

    class Q_WAYLAND_CLIENT_CURSOR_SHAPE_V1_EXPORT wp_cursor_shape_device_v1
    {
    public:
        wp_cursor_shape_device_v1(struct ::wl_registry *registry, uint32_t id, int version);
        wp_cursor_shape_device_v1(struct ::wp_cursor_shape_device_v1 *object);
        wp_cursor_shape_device_v1();

        virtual ~wp_cursor_shape_device_v1();

        void init(struct ::wl_registry *registry, uint32_t id, int version);
        void init(struct ::wp_cursor_shape_device_v1 *object);

        struct ::wp_cursor_shape_device_v1 *object() { return m_wp_cursor_shape_device_v1; }
        const struct ::wp_cursor_shape_device_v1 *object() const { return m_wp_cursor_shape_device_v1; }
        static wp_cursor_shape_device_v1 *fromObject(struct ::wp_cursor_shape_device_v1 *object);

        bool isInitialized() const;

        uint32_t version() const;
        static const struct ::wl_interface *interface();

        enum shape {
            shape_default = 1, // default cursor
            shape_context_menu = 2, // a context menu is available for the object under the cursor
            shape_help = 3, // help is available for the object under the cursor
            shape_pointer = 4, // pointer that indicates a link or another interactive element
            shape_progress = 5, // progress indicator
            shape_wait = 6, // program is busy, user should wait
            shape_cell = 7, // a cell or set of cells may be selected
            shape_crosshair = 8, // simple crosshair
            shape_text = 9, // text may be selected
            shape_vertical_text = 10, // vertical text may be selected
            shape_alias = 11, // drag-and-drop: alias of/shortcut to something is to be created
            shape_copy = 12, // drag-and-drop: something is to be copied
            shape_move = 13, // drag-and-drop: something is to be moved
            shape_no_drop = 14, // drag-and-drop: the dragged item cannot be dropped at the current cursor location
            shape_not_allowed = 15, // drag-and-drop: the requested action will not be carried out
            shape_grab = 16, // drag-and-drop: something can be grabbed
            shape_grabbing = 17, // drag-and-drop: something is being grabbed
            shape_e_resize = 18, // resizing: the east border is to be moved
            shape_n_resize = 19, // resizing: the north border is to be moved
            shape_ne_resize = 20, // resizing: the north-east corner is to be moved
            shape_nw_resize = 21, // resizing: the north-west corner is to be moved
            shape_s_resize = 22, // resizing: the south border is to be moved
            shape_se_resize = 23, // resizing: the south-east corner is to be moved
            shape_sw_resize = 24, // resizing: the south-west corner is to be moved
            shape_w_resize = 25, // resizing: the west border is to be moved
            shape_ew_resize = 26, // resizing: the east and west borders are to be moved
            shape_ns_resize = 27, // resizing: the north and south borders are to be moved
            shape_nesw_resize = 28, // resizing: the north-east and south-west corners are to be moved
            shape_nwse_resize = 29, // resizing: the north-west and south-east corners are to be moved
            shape_col_resize = 30, // resizing: that the item/column can be resized horizontally
            shape_row_resize = 31, // resizing: that the item/row can be resized vertically
            shape_all_scroll = 32, // something can be scrolled in any direction
            shape_zoom_in = 33, // something can be zoomed in
            shape_zoom_out = 34, // something can be zoomed out
        };

        enum error {
            error_invalid_shape = 1, // the specified shape value is invalid
        };

        void destroy();
        void set_shape(uint32_t serial, uint32_t shape);

    private:
        struct ::wp_cursor_shape_device_v1 *m_wp_cursor_shape_device_v1;
    };
}

QT_WARNING_POP
QT_END_NAMESPACE

#endif

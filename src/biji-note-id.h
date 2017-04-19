/* bjb-note-id.h
 * Copyright (C) Pierre-Yves LUYTEN 2012 <py@luyten.fr>
 * 
 * bijiben is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * bijiben is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef _BIJI_NOTE_ID_H_
#define _BIJI_NOTE_ID_H_

#include <glib-object.h>
#include <gtk/gtk.h>

#include "biji-info-set.h"
#include "biji-tracker.h"

G_BEGIN_DECLS

#define BIJI_TYPE_NOTE_ID             (biji_note_id_get_type ())
#define BIJI_NOTE_ID(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), BIJI_TYPE_NOTE_ID, BijiNoteID))
#define BIJI_NOTE_ID_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), BIJI_TYPE_NOTE_ID, BijiNoteIDClass))
#define BIJI_IS_NOTE_ID(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BIJI_TYPE_NOTE_ID))
#define BIJI_IS_NOTE_ID_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), BIJI_TYPE_NOTE_ID))
#define BIJI_NOTE_ID_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), BIJI_TYPE_NOTE_ID, BijiNoteIDClass))



typedef struct _BijiNoteIDClass BijiNoteIDClass;
typedef struct _BijiNoteID BijiNoteID;

typedef struct _BijiNoteIDPrivate BijiNoteIDPrivate;

struct _BijiNoteIDClass
{
  GObjectClass parent_class;
};

struct _BijiNoteID
{
  GObject parent_instance;
  BijiNoteIDPrivate* priv;
};

GType             biji_note_id_get_type                           (void) G_GNUC_CONST;


gboolean          biji_note_id_equal                              (BijiNoteID *a, BijiNoteID *b);


const gchar      *biji_note_id_get_path                           (BijiNoteID *note);


void              biji_note_id_set_title                          (BijiNoteID* n, gchar* title);


const gchar      *biji_note_id_get_title                          (BijiNoteID* n);


gboolean          biji_note_id_set_content                        (BijiNoteID *id, gchar *content);


const gchar      *biji_note_id_get_content                        (BijiNoteID *id);


gint64            biji_note_id_get_mtime                          (BijiNoteID *n);


gboolean          biji_note_id_set_mtime                          (BijiNoteID* n, gint64 mtime);


gint64            biji_note_id_get_last_metadata_change_date      (BijiNoteID* n);


gboolean          biji_note_id_set_last_metadata_change_date      (BijiNoteID* n, gint64 mtime);


gint64            biji_note_id_get_create_date                    (BijiNoteID* n);


gboolean          biji_note_id_set_create_date                    (BijiNoteID* n, gint64 mtime);


BijiNoteID        *biji_note_id_new_from_info                     (BijiInfoSet *info);


G_END_DECLS

#endif /* _BIJI_NOTE_ID_H_ */

#include <stdio.h>
#include <stdint.h>

#include <QPluginLoader>
#include <QMetaObject>
#include <QMetaClassInfo>

int main(int argc, const char *argv[]) {
	for (int i = 1; i < argc; ++ i) {
		const char *pluginfile = argv[i];
		QPluginLoader loader(pluginfile);
		if (!loader.load()) {
			fprintf(stderr, "*** error: %s: %s\n", pluginfile, qPrintable(loader.errorString()));
		}
		else {
			QObject *instance = loader.instance();
			if (!instance) {
				fprintf(stderr, "*** error: %s: instance is NULL\n", pluginfile);
			}
			else {
				printf("plugin: %s\n",pluginfile);
				printf("address: 0x%zx\n",(intptr_t)instance);
				printf("object name: %s\n",qPrintable(instance->objectName()));

				const QMetaObject *meta = instance->metaObject();
				while (meta) {
					printf("class name: %s\n",meta->className());

					int i = meta->classInfoOffset();
					int n = meta->classInfoCount();
					if (i < n) {
						printf("class info:\n");
						for (; i < n; ++ i) {
							QMetaClassInfo info = meta->classInfo(i);
							printf("\t%s: %s\n",info.name(),info.value());
						}
					}

					meta = meta->superClass();
				}
			}
			printf("\n");
		}
	}
	return 0;
}

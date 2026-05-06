# f1-app-chart/templates/_helpers.tpl
{{- define "f1-app-chart.name" -}}
{{- .Chart.Name -}}
{{- end -}}

{{- define "f1-app-chart.labels" -}}
helm.sh/chart: {{ .Chart.Name }}-{{ .Chart.Version }}
app.kubernetes.io/managed-by: {{ .Release.Service }}
{{- end -}}

{{- define "f1-app-chart.selectorLabels" -}}
app.kubernetes.io/name: {{ include "f1-app-chart.name" . }}
app.kubernetes.io/instance: {{ .Release.Name }}
{{- end -}}